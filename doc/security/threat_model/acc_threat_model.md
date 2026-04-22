# Asymmetric Cryptographic Coprocessor (ACC) Threat Model

This document details the threat model for the Asymmetric Cryptographic Coprocessor (ACC), as utilized by the *cryptolib* cryptographic library to implement classical and post-quantum cryptography in the Pavona silicon root of trust (RoT) designs.

## Introduction

ACC overview: The Asymmetric Cryptographic Coprocessor (ACC) is the programmable cryptographic coprocessor included in Pavona’s RoT designs. The ACC itself provides acceleration for operations including:

* RSA-2048, RSA-3072, and RSA-4096 keygen
* RSA-2048, RSA-3072, and RSA-4096 PKCS v1.5 signatures
* RSA-2048, RSA-3072, and RSA-4096 PSS signatures
* RSA-2048, RSA-3072, and RSA-4096 OAEP encryption
* ECDSA with NIST P-256 and NIST P-384 curves
* ECDH with NIST P-256 and NIST P-384 curves
* Ed25519
* X25519
* ML-KEM-{512,768,1024}
* ML-DSA-{44,65,87}

At its core, the ACC consists of a highly customized lightweight processor containing a 32-bit general purpose register bank and a separate 256-bit wide register bank with corresponding bignum instructions. By reusing these wide registers as vector registers, a vectorized ISA is implemented without introducing an additional bank, allowing for performant and area-efficient implementation of various post-quantum cryptographic algorithms, especially ML-KEM and ML-DSA.

ACC programs are loaded by the primary RoT core into an instruction memory (IMEM), and inputs and outputs are passed to/from the primary RoT core via the data memory (DMEM). A small section of DMEM is reserved as scratchpad memory for the DMEM, such that the primary RoT core cannot access anything placed in that section.

To allow for hardware-backed keys which are never exposed to the primary RoT core, a sideloading datapath from the key manager to the ACC can be used. Moreover, to support fast ML-KEM and ML-DSA implementations with hardware-backed keys, a direct interface from the ACC to the fixed KMAC/SHA-3/SHAKE engine is provided.

ACC and cryptolib: In general, the cryptolib implementations for ACC-backed operations (including all ML-KEM and ML-DSA operations) load the appropriate program into ACC IMEM, load provided inputs into the ACC DMEM, start the ACC via a designated CSR,  and on ACC completion fetch the results from ACC DMEM. There are some small additional steps taken on the primary processor for defense-in-depth, but the cryptolib implementations for ACC-backed operations still lie almost entirely in the ACC programs used; this is correspondingly where virtually all SCA mitigations take place.

ACC PQC performance: Careful attention has been paid in particular to the vectorized ISA extensions used in the ACC ML-KEM and ML-DSA implementations. For a detailed analysis of how the ISA extensions have been designed in a performant and area-conscious way, see the initial *Towards ML-KEM & ML-DSA on Opentitan* ([https://eprint.iacr.org/2024/1192](https://eprint.iacr.org/2024/1192)) and subsequent *Improving ML-KEM and ML-DSA on OpenTitan* ([https://eprint.iacr.org/2025/2028](https://eprint.iacr.org/2025/2028)) papers.

## Scope: Attack Methods

Timing attacks: As part of our analysis regarding side-channel attacks, we include all manner of timing attacks, including cache timing attacks, to be within scope.

Passive physical attacks: we further consider power and electromagnetic side-channels to be in scope.

Active physical attacks: Differential faulting attacks as a form of SCA are also included in scope, but for protecting against fault-injection attacks in general, we strongly recommend dual-core lockstep configurations of the ACC to be used. More defense-in-depth approaches are discussed below.

Operations considered: All security assets used or generated in the course of key generation, encryption/decryption, signing/verification, or key encapsulation/decapsulation are considered within scope for these attacks.

Profiled vs. non-profiled attacks: In the following, we implicitly combine discussion of profiled (e.g. CPA) and non-profiled (e.g. SPA) side-channel attacks, as e.g. for operations like keygen, we may want to assume that an attacker has some limited ability to, say, replay entropy through an operation. Moreover, the protections at the hardware level against both types of attacks are the same, and generally speaking the same primitive operations are usually involved in other repeatable operations as in keygen.

## Scope: Security Assets

Private keys: In this analysis, we consider all private keys stored in the ACC, including those derived as a result of an operation (e.g. the resulting keys from keygen operations, or KEM encapsulation/decapsulation) security assets which must be protected from an attacker employing the above methods.

User-provided secret values: Other user-provided secret values, such as plaintexts for encryption, are similarly designated as security assets.

Intermediate results: Additionally, any intermediate value computed by the ACC which could reveal a non-negligible amount of information about one of the above security assets must also be treated as a security asset.

## Mitigations: Overall

Timing side-channel mitigations: To address timing side-channels, ACC programs can be statically analyzed using a purpose-built tool to construct their control flow graph and ensure that no branches (aside from e.g. signature rejection loopback in ML-DSA) depend on secret values. These checks as currently performed are done as recurring tests in CI, preventing accidental introduction of timing side-channels after changes to an ACC program.

Additionally, all ACC instructions take the same number of cycles regardless of ACC state. In particular, ACC branch instructions are implemented to take the same number of cycles regardless of whether the branch is taken or not; this fact is also used to prevent Spectre-style speculative execution attacks on the ACC. To allow fast conditionals, a single-cycle WDR ‘select’ instruction is used. See [*From Artifact to Production: Integrating and Refining Lattice Cryptography Acceleration*](https://www.zerorisc.com/blog/from-artifact-to-production-integrating-and-refining-lattice-cryptography-acceleration) for an in-depth example of optimizing ML-KEM rejection sampling using this approach.

Passive side-channel mitigations: Standard mitigations such as first-order masking and blinding have been used extensively throughout e.g. the P-256 and P-384 implementations. Prior analysis using CocoAlma on SCA traces from FPGA builds has been used to determine the set of cases where shares may interact in the ACC datapath, including motifs which cause transient leakage, and in turn care has been taken to avoid and eliminate these constructions in the code.

Active side-channel mitigations: As noted above, a dual-core lockstep ACC implementation is the primary recommended approach for mitigating active attacks. This said, there are several defense-in-depth mechanisms also employed, including PRINCE scrambling for ACC memories, running hardware checksums for DMEM writes, and hardened runtime comparisons of ACC instruction counts to statically-determined runtime bounds.

## Further Mitigations: ML-KEM and ML-DSA

Elimination of transient leakage: The next revision of the ACC will prevent the above-mentioned transient leakage side-channel vectors at the hardware level via modification of the ACC pipeline now that these existing leakages have been properly characterized.

First-order masking for SHAKE: To allow for a fully first-order masked ML-KEM/ML-DSA implementation, the hardware implementing the SHAKE operation will be modified to accept two message shares instead of only a single unmasked message. Presently, a parameter for the KMAC/SHA-3/SHAKE IP block allows splitting input messages into shares, extending domain-oriented masking to them, but the input registers only allow for a single message share. As such, the KMAC/SHA-3/SHAKE engine as well as the direct interface to/from the ACC is being reworked to allow for providing an input message as two shares.

Masking ISA extensions: In order to efficiently implement a masked version of e.g. ML-KEM, performant support for secure arithmetic share addition, A2B/B2A share conversion, and decompressed comparison are needed. ISA extensions are actively being designed in order to allow for fast masking of these necessary operations while minimizing additional area overhead.

## Proposed Empirical SCA Methodology

Planned methodology: For initial assessment and continuous integration (CI) evaluation of side-channel leakage, standard TVLA methodology (fixed vs. random Welch’s t-test) will be used with a ChipWhisperer CW310 Kintex K410T FPGA board as target, testing isolated routines (pointwise multiplication, NTT/INTT, message decoding, etc.) as well as full instantiations of ML-KEM, e.g. a plaintext-checking oracle. More extensive follow-up analyses will be performed using detailed manual inspection of traces, including evaluation of techniques from prominent recent attacks, e.g. [HNP+24](https://eprint.iacr.org/2024/060)’s practical attacks on high-order masked comparison gadgets.

## Formal Verification Methodology

Rocq model of ACC: Presently, for difficult sections of ACC programs, a Rocq model of the ACC has been used to verify correctness; for instance, a proof of correctness of the technique used for fast modular multiplication routine used by Ed25519 can be found [here](https://github.com/zerorisc/otbn-model/blob/main/Otbn/Examples/FeMul25519.v).

Jasmin implementation: Going forward, efforts as alluded to in the cross-posted MPI-SP blog post [*Accelerating Post-Quantum Cryptography on OpenTitan-based Designs: Flexible Hardware for a Secure Future*](https://www.zerorisc.com/blog/accelerating-post-quantum-cryptography-on-opentitan-based-designs-flexible-hardware-for-a-secure-future) to move ACC programs into the Jasmin high-assurance cryptography language will allow for direct binding of proofs to the actual ACC assembly, and will also allow for automatic deduction of security properties regarding side-channel leakage.


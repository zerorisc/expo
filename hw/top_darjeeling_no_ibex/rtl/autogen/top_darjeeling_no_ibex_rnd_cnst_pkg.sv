// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0
//
// ------------------- W A R N I N G: A U T O - G E N E R A T E D   C O D E !! -------------------//
// PLEASE DO NOT HAND-EDIT THIS FILE. IT HAS BEEN AUTO-GENERATED WITH THE FOLLOWING COMMAND:
//
// util/topgen.py -t hw/top_darjeeling_no_ibex/data/top_darjeeling_no_ibex.hjson \
//                -o hw/top_darjeeling_no_ibex/ \
//                --rnd_cnst_seed \
//                1017106219537032642877583828875051302543807092889754935647094601236425074047


package top_darjeeling_no_ibex_rnd_cnst_pkg;

  ////////////////////////////////////////////
  // otp_ctrl
  ////////////////////////////////////////////
  // Compile-time random bits for initial LFSR seed
  parameter otp_ctrl_top_specific_pkg::lfsr_seed_t RndCnstOtpCtrlLfsrSeed = {
    40'hCD_A9A5FCEB
  };

  // Compile-time random permutation for LFSR output
  parameter otp_ctrl_top_specific_pkg::lfsr_perm_t RndCnstOtpCtrlLfsrPerm = {
    240'h5CA7_514DF488_95654290_C14125E0_1884E99C_12364F2D_40C719B8_903676A0
  };

  // Compile-time random permutation for scrambling key/nonce register reset value
  parameter otp_ctrl_top_specific_pkg::scrmbl_key_init_t RndCnstOtpCtrlScrmblKeyInit = {
    256'h58FA9063_CE216C0B_412615D7_3F476529_A96A1A8A_CA4B0BDC_BE6B240C_31095162
  };

  ////////////////////////////////////////////
  // lc_ctrl
  ////////////////////////////////////////////
  // Diversification value used for all invalid life cycle states.
  parameter lc_ctrl_pkg::lc_keymgr_div_t RndCnstLcCtrlLcKeymgrDivInvalid = {
    128'hE41BF99B_2BC41E9E_DBB4685F_7EB27EB3
  };

  // Diversification value used for the TEST_UNLOCKED* life cycle states.
  parameter lc_ctrl_pkg::lc_keymgr_div_t RndCnstLcCtrlLcKeymgrDivTestUnlocked = {
    128'hB35F3527_52E34F64_CE978305_BFC3481A
  };

  // Diversification value used for the DEV life cycle state.
  parameter lc_ctrl_pkg::lc_keymgr_div_t RndCnstLcCtrlLcKeymgrDivDev = {
    128'h2162EA27_92B7508F_1EAB067A_F954DDA5
  };

  // Diversification value used for the PROD/PROD_END life cycle states.
  parameter lc_ctrl_pkg::lc_keymgr_div_t RndCnstLcCtrlLcKeymgrDivProduction = {
    128'h491439A9_DDE63208_01FDCF25_A4FBA528
  };

  // Diversification value used for the RMA life cycle state.
  parameter lc_ctrl_pkg::lc_keymgr_div_t RndCnstLcCtrlLcKeymgrDivRma = {
    128'h39911706_9E77C887_F53DDA6F_B4EF8758
  };

  // Compile-time random bits used for invalid tokens in the token mux
  parameter lc_ctrl_pkg::lc_token_mux_t RndCnstLcCtrlInvalidTokens = {
    256'hB99027B6_AA7468BC_0BD8D703_68E7CFB1_1A99675B_14624061_9335A9E2_D123834D,
    256'h18744778_BE5E63C0_87E36838_B56B1A45_F6FD312F_5353FA7B_2CE9FC83_DDAF1DD8,
    256'hC5A42E2A_D24FA022_21B6FF5A_AD7A9C09_D5D9FDD1_CFCF5128_35C0CFAE_2ED0C69F,
    256'hA488685C_EA9BC1C8_9BFB7399_AEF5C6EB_5D6E4E23_416A0AA6_D7AC7EC9_C3304470
  };

  ////////////////////////////////////////////
  // alert_handler
  ////////////////////////////////////////////
  // Compile-time random bits for initial LFSR seed
  parameter alert_handler_pkg::lfsr_seed_t RndCnstAlertHandlerLfsrSeed = {
    32'hFBE505F9
  };

  // Compile-time random permutation for LFSR output
  parameter alert_handler_pkg::lfsr_perm_t RndCnstAlertHandlerLfsrPerm = {
    160'h7EA97F41_618DB861_9EAAEE1C_8209A5DA_7F3C824C
  };

  ////////////////////////////////////////////
  // sram_ctrl_ret_aon
  ////////////////////////////////////////////
  // Compile-time random reset value for SRAM scrambling key.
  parameter otp_ctrl_pkg::sram_key_t RndCnstSramCtrlRetAonSramKey = {
    128'h246C4264_F37EC198_201794AD_DA1B1692
  };

  // Compile-time random reset value for SRAM scrambling nonce.
  parameter otp_ctrl_pkg::sram_nonce_t RndCnstSramCtrlRetAonSramNonce = {
    128'h9DF5E06A_56AADED4_43259FFB_5736DD68
  };

  // Compile-time random bits for initial LFSR seed
  parameter sram_ctrl_pkg::lfsr_seed_t RndCnstSramCtrlRetAonLfsrSeed = {
    64'h01215B98_E162DCC0
  };

  // Compile-time random permutation for LFSR output
  parameter sram_ctrl_pkg::lfsr_perm_t RndCnstSramCtrlRetAonLfsrPerm = {
    128'hE2AC3B98_3855BD0B_2D0A5663_6D210A1C,
    256'h08895B16_1FD1EFFD_93CF8170_63CDCAE5_1382B5E8_6B7D45A5_D236CF94_4B3BA327
  };

  ////////////////////////////////////////////
  // aes
  ////////////////////////////////////////////
  // Default seed of the PRNG used for register clearing.
  parameter aes_pkg::clearing_lfsr_seed_t RndCnstAesClearingLfsrSeed = {
    64'hDF6A55F0_D23BB7DC
  };

  // Permutation applied to the LFSR of the PRNG used for clearing.
  parameter aes_pkg::clearing_lfsr_perm_t RndCnstAesClearingLfsrPerm = {
    128'h3875E861_96A6B9D9_D3A5B3FB_E042DE8F,
    256'hE1764300_A1AF2B41_19C93936_0CD4AAFF_3F496D4C_7CA97DDE_223A0115_6CD09C43
  };

  // Permutation applied to the clearing PRNG output for clearing the second share of registers.
  parameter aes_pkg::clearing_lfsr_perm_t RndCnstAesClearingSharePerm = {
    128'h76B2231D_488F580D_C16307CD_C7E56ED3,
    256'hAA939AF3_3F29BB49_F0E9255C_52DA0D9F_42D767B2_E3946CED_01334A0A_069DC869
  };

  // Default seed of the PRNG used for masking.
  parameter aes_pkg::masking_lfsr_seed_t RndCnstAesMaskingLfsrSeed = {
    32'h4FB06B9E,
    256'hA47DBF44_1AA625F5_DDF2DCB0_3C2B8670_24D54654_C6E64E7A_AC13CB5D_D2F3DDBB
  };

  // Permutation applied to the output of the PRNG used for masking.
  parameter aes_pkg::masking_lfsr_perm_t RndCnstAesMaskingLfsrPerm = {
    256'h503D6861_08074C74_3356290C_6D163234_91532B2F_181F4879_172D990D_3A0F609E,
    256'h202E8B5F_6B808E41_4F058909_397C1B0E_73464A4B_92025587_43456996_8A124E9F,
    256'h253F867B_6C19574D_5993902C_6E679813_88651D72_479D8C23_3E22703B_8438421C,
    256'h515B7F01_780A8376_855C249B_522A5811_5E213700_267D1E40_04449C82_149A1A77,
    256'h7A6A8D94_8F35816F_757E0B62_3031063C_49546366_10150327_365A955D_64719728
  };

  ////////////////////////////////////////////
  // kmac
  ////////////////////////////////////////////
  // Compile-time random data for PRNG default seed
  parameter kmac_pkg::lfsr_seed_t RndCnstKmacLfsrSeed = {
    32'h452480A6,
    256'h1092E8A8_0CDF2678_89E06A8A_1AB5F6DB_8158AA7C_98DDEC28_34FDD682_25AC00E6
  };

  // Compile-time random permutation for PRNG output
  parameter kmac_pkg::lfsr_perm_t RndCnstKmacLfsrPerm = {
    64'hA2269242_199B14C0,
    256'hD6F316E1_A9005719_0D034D1F_02E4676D_8A4B70B3_F9946A07_68E15649_D5D14423,
    256'hA9E5A0BD_47472D05_DB04226E_1C487FBE_8498D833_9BD879AC_9FBF2679_FB1D1357,
    256'hB9B47194_86705EB2_5797F6C8_75101508_38A47E6D_1B728B4E_23D25182_B9545BC5,
    256'h0C760419_281A2B4D_B68981BA_EA93E1BA_84CB2166_684771CB_BC385344_BB68B981,
    256'h4EC48939_32ABCC7C_55C605EA_D2FB5CC6_0B5A2493_47279F13_83E65668_636A4F48,
    256'hC6F6AA92_08A8CE68_06D61666_2A535171_666D6EC7_F1DCA55B_F560F927_6B671D34,
    256'h7F52A68C_70296B13_68BF3F01_97FC5408_8E34CDB6_74B11140_471E9899_09623A06,
    256'h2BD3199C_DCC991E1_85025C18_8E736BD2_6C3F86D5_2A66DEAD_47956516_052B7895,
    256'hC6A682A0_AE8DA29E_624D3C91_CEE72C1E_BAA2D9F4_7BC34842_DDDE43E2_2ABF020D,
    256'h90A90649_87DFBBA2_977A4301_BACDB0F0_85519209_2C2086A0_80CCCB02_854C5CF6,
    256'hBD0B39A4_378C9E00_ACA1B2BA_7895C21A_D28C8D81_99C47BCA_B9886FAC_E5F01C37,
    256'h664FABFD_2689E093_B43C1DDC_32085A04_820AECFD_17E266B9_06422E07_223FA455,
    256'hB03E3E72_9658A183_4DA3A9B9_741325E5_5557A52C_EAFDB883_7145924C_738F27D8,
    256'h3A5F6828_2E484926_ABDEE78A_650014E4_11A90751_095E03D1_A9AD6721_EC6C524B,
    256'h31770A11_69103B74_7C5A5A59_C9772282_6886A33C_D5A6A8A1_580A25BD_3F9E4535,
    256'h0B15638B_47AA9B2A_14E7E9E5_46123C00_D44540A4_F48C518A_F5F869B0_6D7112A8,
    256'h52D86114_4313EF28_32D5018C_2401D570_0D73187E_07D37BF9_67822A63_AADB96CA,
    256'hA9856849_56B1770F_2669F6EE_F80EC329_ECEFAAEE_DC591293_A06AFAE4_B1465BE5,
    256'h2E53D512_201175A7_11D1A1A1_80367993_22C4E389_4109E9C0_62340A60_43357265,
    256'hC98055ED_5C5B1255_9D1870C3_C58D2BA7_72C27C84_12B7ACB5_801D9642_4BBF4CB7,
    256'hD47D77D8_84A16AAC_104485F3_9D623B50_FB3828C2_98D5465D_30700C31_6E27A283,
    256'h64698C04_E18F10D9_71BDB7E8_7004F6A7_85670487_259D7010_A04A41BA_101D20D5,
    256'hFB3292B1_C80A86B9_0231A80A_814BE5D9_C1530D29_3025BE46_930520BE_450D2ABA,
    256'h18B4DE03_66898C16_E950E73D_DEE85A7F_478DC394_FF5B6566_2C8D9E14_4C24A712,
    256'h8CF21458_791F1848_C385DF0A_B43E4425_39109152_5BC00215_5E5AB876_E97431E9,
    256'h3CF06D03_9344EB91_660B2E55_3D563311_073022B7_B0BA8709_AC2AD88B_0782C5AC,
    256'h04105038_D6B3D989_8D0E7265_9A942CC3_8E9B1AE3_4ED3A829_F405A516_DCC7B663,
    256'h32D8C17F_9A7775F8_B9980324_BD880DF4_5E742B2E_E5D6F540_48FA3A39_5E9115B2,
    256'h2E8EE766_7DF24C9B_3120132E_C4227081_2F02EAB0_737691B4_F9F7375A_66C20765,
    256'h89232237_3786828E_B8502C47_14B863CB_350C2DC0_D02C1EC9_66E96C15_615C258A,
    256'h3E9D8BC2_8B203174_57C80497_A02F0A88_0D44D95A_91846323_59EB101A_DB995D4A
  };

  // Compile-time random data for PRNG buffer default seed
  parameter kmac_pkg::buffer_lfsr_seed_t RndCnstKmacBufferLfsrSeed = {
    32'h2246562D,
    256'hCCEDA3A4_23366A80_96B121FA_42246B6C_385A5AA3_B4FE9C0A_8D1F2128_E03E0B01,
    256'h632E027E_34C81340_BCFD0FD5_3473B544_0B76763B_45BCA816_6865FDAF_59F386D5,
    256'h174CC7F5_FD1F544B_3A82C54E_1481730F_66854723_D0056094_5B6C126F_FEC03BF1
  };

  // Compile-time random permutation for LFSR Message output
  parameter kmac_pkg::msg_perm_t RndCnstKmacMsgPerm = {
    128'hB9C2273F_03A025FF_456FAB7C_566BF4E4,
    256'h74544FB5_98D73902_34BDDAC6_888C0DE1_B6499401_13E969FE_CE0A7725_EB8C086A
  };

  ////////////////////////////////////////////
  // otbn
  ////////////////////////////////////////////
  // Default seed of the PRNG used for URND.
  parameter otbn_pkg::urnd_prng_seed_t RndCnstOtbnUrndPrngSeed = {
    256'hF8A394A0_94C63C8A_F070919C_D8B168CA_B6A734A2_A92B34BA_17C53191_1E20C1A4
  };

  // Compile-time random reset value for IMem/DMem scrambling key.
  parameter otp_ctrl_pkg::otbn_key_t RndCnstOtbnOtbnKey = {
    128'h96592784_AC089E72_877BDAF9_F7954486
  };

  // Compile-time random reset value for IMem/DMem scrambling nonce.
  parameter otp_ctrl_pkg::otbn_nonce_t RndCnstOtbnOtbnNonce = {
    64'h164B58EA_68F9B7F6
  };

  ////////////////////////////////////////////
  // keymgr_dpe
  ////////////////////////////////////////////
  // Compile-time random bits for initial LFSR seed
  parameter keymgr_pkg::lfsr_seed_t RndCnstKeymgrDpeLfsrSeed = {
    64'h47CDAFC1_C9A905A7
  };

  // Compile-time random permutation for LFSR output
  parameter keymgr_pkg::lfsr_perm_t RndCnstKeymgrDpeLfsrPerm = {
    128'hDFC0E31D_C106C730_1A9ECE4C_BD726063,
    256'h858DBA46_554F47F2_7928A122_D3BAD9B0_6B99DA7F_091D7028_BF9094FA_05F7B52A
  };

  // Compile-time random permutation for entropy used in share overriding
  parameter keymgr_pkg::rand_perm_t RndCnstKeymgrDpeRandPerm = {
    160'h3F4D14A9_62F03037_66EC0934_5B538DDC_A7F43E15
  };

  // Compile-time random bits for revision seed
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeRevisionSeed = {
    256'h6E77B99B_F0A1BCD6_7FB8941C_331A4427_7BC08F71_1D2D33E7_2BC40A36_399D8364
  };

  // Compile-time random bits for software generation seed
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeSoftOutputSeed = {
    256'hDCD59508_D525078E_802F91D8_583804FD_E71271F1_738C1CAC_987A6B8A_7758B762
  };

  // Compile-time random bits for hardware generation seed
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeHardOutputSeed = {
    256'h216EDD63_070949C7_834AB6EE_6E7AD485_FF3CA72C_2242223C_E6D70F17_B4F4B328
  };

  // Compile-time random bits for generation seed when aes destination selected
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeAesSeed = {
    256'h18AA49D1_25B4DEFB_1F3C0BE8_A29BE065_C26D2355_0BBC139F_F6461763_D7E966A8
  };

  // Compile-time random bits for generation seed when kmac destination selected
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeKmacSeed = {
    256'hA7219EB2_E8EF9F11_A152E6C7_1AA23B88_64416E75_0C01A333_9C6C7AA1_1244ECD2
  };

  // Compile-time random bits for generation seed when otbn destination selected
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeOtbnSeed = {
    256'h8A62CB1B_851078C2_A5F18EEE_28D0B562_043B7312_EFAD871F_92E7527D_A865D661
  };

  // Compile-time random bits for generation seed when no destination selected
  parameter keymgr_pkg::seed_t RndCnstKeymgrDpeNoneSeed = {
    256'h281FE98D_FCD72E3C_6D150A85_D6300959_6F7966C5_C68CAEDD_E4AB7C65_FB8D5961
  };

  ////////////////////////////////////////////
  // csrng
  ////////////////////////////////////////////
  // Compile-time random bits for csrng state group diversification value
  parameter csrng_pkg::cs_keymgr_div_t RndCnstCsrngCsKeymgrDivNonProduction = {
    128'h8284064D_7194E470_7ADA81F8_A6DB14CA,
    256'h845BEEE6_0798289A_D4FB0DF1_76829639_0152700E_078EC5A9_51B627CF_2CCD155D
  };

  // Compile-time random bits for csrng state group diversification value
  parameter csrng_pkg::cs_keymgr_div_t RndCnstCsrngCsKeymgrDivProduction = {
    128'h84FDACED_736E9336_2C8DA83C_5F4DD209,
    256'h3E4D2A70_DD99DCF4_CCAC341A_2F1A2704_F5E21287_FA168AF2_51B370D0_34CDA605
  };

  ////////////////////////////////////////////
  // sram_ctrl_main
  ////////////////////////////////////////////
  // Compile-time random reset value for SRAM scrambling key.
  parameter otp_ctrl_pkg::sram_key_t RndCnstSramCtrlMainSramKey = {
    128'h152662F4_D11B3245_D5943EA5_FD2E4BEA
  };

  // Compile-time random reset value for SRAM scrambling nonce.
  parameter otp_ctrl_pkg::sram_nonce_t RndCnstSramCtrlMainSramNonce = {
    128'h016B7911_DEAF01DF_74254737_1445D6E3
  };

  // Compile-time random bits for initial LFSR seed
  parameter sram_ctrl_pkg::lfsr_seed_t RndCnstSramCtrlMainLfsrSeed = {
    64'h955145E3_074D9CA9
  };

  // Compile-time random permutation for LFSR output
  parameter sram_ctrl_pkg::lfsr_perm_t RndCnstSramCtrlMainLfsrPerm = {
    128'h839F7F3C_512A2A1A_F31ADD8C_8B867C90,
    256'hB5687252_6C013503_99F59137_41DEBAF4_317489C2_DDA61B3B_5C328D74_BE07BA7A
  };

  ////////////////////////////////////////////
  // sram_ctrl_mbox
  ////////////////////////////////////////////
  // Compile-time random reset value for SRAM scrambling key.
  parameter otp_ctrl_pkg::sram_key_t RndCnstSramCtrlMboxSramKey = {
    128'h29BD781E_FE2B4B06_F4B349E0_372B7394
  };

  // Compile-time random reset value for SRAM scrambling nonce.
  parameter otp_ctrl_pkg::sram_nonce_t RndCnstSramCtrlMboxSramNonce = {
    128'hD415D937_F3578CC1_200DD1FB_1D0ECF94
  };

  // Compile-time random bits for initial LFSR seed
  parameter sram_ctrl_pkg::lfsr_seed_t RndCnstSramCtrlMboxLfsrSeed = {
    64'h8594BC83_1C3E0E1F
  };

  // Compile-time random permutation for LFSR output
  parameter sram_ctrl_pkg::lfsr_perm_t RndCnstSramCtrlMboxLfsrPerm = {
    128'h392500F4_625987FC_175BB8F4_AE86EC56,
    256'h58103487_53A6215A_E4405F3D_1DDC9EA7_B8BB31FC_90B2BAD4_3B42C766_2FFA6C8C
  };

  ////////////////////////////////////////////
  // rom_ctrl0
  ////////////////////////////////////////////
  // Fixed nonce used for address / data scrambling
  parameter bit [63:0] RndCnstRomCtrl0ScrNonce = {
    64'h435205EF_40D4B50C
  };

  // Randomised constant used as a scrambling key for ROM data
  parameter bit [127:0] RndCnstRomCtrl0ScrKey = {
    128'hBD86B493_2D75CEBE_7060738E_FA203541
  };

  ////////////////////////////////////////////
  // rom_ctrl1
  ////////////////////////////////////////////
  // Fixed nonce used for address / data scrambling
  parameter bit [63:0] RndCnstRomCtrl1ScrNonce = {
    64'h8082CFE9_6E5CC128
  };

  // Randomised constant used as a scrambling key for ROM data
  parameter bit [127:0] RndCnstRomCtrl1ScrKey = {
    128'h0FBE2F2E_323688BC_C7ECBB1A_7DB7BE4C
  };

endpackage : top_darjeeling_no_ibex_rnd_cnst_pkg

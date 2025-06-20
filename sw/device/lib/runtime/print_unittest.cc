// Copyright lowRISC contributors (OpenTitan project).
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

// print.h's polyglotness is not part of its public API at the moment; we wrap
// it in an `extern` here for the time being.
extern "C" {
#include "sw/device/lib/runtime/print.h"
}  // extern "C"

#include <stdint.h>
#include <string>

#include "absl/strings/str_format.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "sw/device/lib/base/status.h"
#include "sw/device/lib/dif/dif_uart.h"

// NOTE: This is only present so that print.c can link without pulling in
// dif_uart.c.
extern "C" dif_result_t dif_uart_byte_send_polled(const dif_uart *, uint8_t) {
  return kDifOk;
}

namespace base {
namespace {

using ::testing::StartsWith;

// A test fixture for automatiocally capturing stdout.
class PrintfTest : public testing::Test {
 protected:
  void SetUp() override {
    base_set_stdout({
        .data = static_cast<void *>(&buf_),
        .sink =
            +[](void *data, const char *buf, size_t len) {
              static_cast<std::string *>(data)->append(buf, len);
              return len;
            },
    });
  }

  std::string buf_;
};

TEST_F(PrintfTest, EmptyFormat) {
  EXPECT_EQ(base_printf(""), 0);
  EXPECT_EQ(buf_, "");
}

TEST_F(PrintfTest, TrivialText) {
  EXPECT_EQ(base_printf("Hello, World!\n"), 14);
  EXPECT_EQ(buf_, "Hello, World!\n");
}

TEST_F(PrintfTest, PartialPrints) {
  EXPECT_EQ(base_printf("Hello, "), 7);
  EXPECT_EQ(buf_, "Hello, ");
  EXPECT_EQ(base_printf("World!\n"), 7);
  EXPECT_EQ(buf_, "Hello, World!\n");
}

TEST_F(PrintfTest, LiteralPct) {
  EXPECT_EQ(base_printf("Hello, %%!\n"), 10);
  EXPECT_EQ(buf_, "Hello, %!\n");
}

TEST_F(PrintfTest, Character) {
  EXPECT_EQ(base_printf("Hello, %c!\n", 'X'), 10);
  EXPECT_EQ(buf_, "Hello, X!\n");
}

TEST_F(PrintfTest, Bool) {
  EXPECT_EQ(base_printf("Hello, %!b, %!b!\n", true, false), 20);
  EXPECT_EQ(buf_, "Hello, true, false!\n");
}

TEST_F(PrintfTest, StringWithNul) {
  EXPECT_EQ(base_printf("Hello, %s!\n", "abcxyz"), 15);
  EXPECT_EQ(buf_, "Hello, abcxyz!\n");
}

TEST_F(PrintfTest, StringWithLen) {
  EXPECT_EQ(base_printf("Hello, %!s!\n", 6, "abcxyz"), 15);
  EXPECT_EQ(buf_, "Hello, abcxyz!\n");
}

TEST_F(PrintfTest, StringWithLenPrefix) {
  EXPECT_EQ(base_printf("Hello, %!s!\n", 3, "abcxyz"), 12);
  EXPECT_EQ(buf_, "Hello, abc!\n");
}

TEST_F(PrintfTest, StringWithLenZeroLen) {
  EXPECT_EQ(base_printf("Hello, %!s!\n", 0, "abcxyz"), 9);
  EXPECT_EQ(buf_, "Hello, !\n");
}

TEST_F(PrintfTest, HexStringWithLen) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!x!\n", 4, &val), 17);
  EXPECT_EQ(buf_, "Hello, deadbeef!\n");
}

TEST_F(PrintfTest, HexStringWithLenPrefix) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!x!\n", 1, &val), 11);
  EXPECT_EQ(buf_, "Hello, ef!\n");
}

TEST_F(PrintfTest, HexStringWithLenZeroLen) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!x!\n", 0, &val), 9);
  EXPECT_EQ(buf_, "Hello, !\n");
}

TEST_F(PrintfTest, UpperHexStringWithLen) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!X!\n", 4, &val), 17);
  EXPECT_EQ(buf_, "Hello, DEADBEEF!\n");
}

TEST_F(PrintfTest, UpperHexStringWithLenPrefix) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!X!\n", 1, &val), 11);
  EXPECT_EQ(buf_, "Hello, EF!\n");
}

TEST_F(PrintfTest, UpperHexStringWithLenZeroLen) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!X!\n", 0, &val), 9);
  EXPECT_EQ(buf_, "Hello, !\n");
}

TEST_F(PrintfTest, LeHexStringWithLen) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!y!\n", 4, &val), 17);
  EXPECT_EQ(buf_, "Hello, efbeadde!\n");
}

TEST_F(PrintfTest, UpperLeHexStringWithLen) {
  uint32_t val = 0xdeadbeef;
  EXPECT_EQ(base_printf("Hello, %!Y!\n", 4, &val), 17);
  EXPECT_EQ(buf_, "Hello, EFBEADDE!\n");
}

TEST_F(PrintfTest, SignedInt) {
  EXPECT_EQ(base_printf("Hello, %i!\n", 42), 11);
  EXPECT_EQ(buf_, "Hello, 42!\n");
}

TEST_F(PrintfTest, SignedIntZero) {
  EXPECT_EQ(base_printf("Hello, %d!\n", 0), 10);
  EXPECT_EQ(buf_, "Hello, 0!\n");
}

TEST_F(PrintfTest, SignedIntAlt) {
  EXPECT_EQ(base_printf("Hello, %d!\n", 42), 11);
  EXPECT_EQ(buf_, "Hello, 42!\n");
}

TEST_F(PrintfTest, SignedIntNegative) {
  EXPECT_EQ(base_printf("Hello, %i!\n", -800), 13);
  EXPECT_EQ(buf_, "Hello, -800!\n");
}

TEST_F(PrintfTest, SignedIntWithWidth) {
  EXPECT_EQ(base_printf("Hello, %3i!\n", 42), 12);
  EXPECT_EQ(buf_, "Hello,  42!\n");
}

TEST_F(PrintfTest, SignedIntWithWidthTooShort) {
  EXPECT_EQ(base_printf("Hello, %3i!\n", 9001), 13);
  EXPECT_EQ(buf_, "Hello, 9001!\n");
}

TEST_F(PrintfTest, SignedIntWithZeros) {
  EXPECT_EQ(base_printf("Hello, %03i!\n", 42), 12);
  EXPECT_EQ(buf_, "Hello, 042!\n");
}

TEST_F(PrintfTest, SignedIntWithZerosTooShort) {
  EXPECT_EQ(base_printf("Hello, %03i!\n", 9001), 13);
  EXPECT_EQ(buf_, "Hello, 9001!\n");
}

TEST_F(PrintfTest, UnsignedInt) {
  EXPECT_EQ(base_printf("Hello, %u!\n", 42), 11);
  EXPECT_EQ(buf_, "Hello, 42!\n");
}

TEST_F(PrintfTest, UnsignedIntNegative) {
  EXPECT_EQ(base_printf("Hello, %u!\n", -1), 19);
  EXPECT_EQ(buf_, "Hello, 4294967295!\n");
}

TEST_F(PrintfTest, HexFromDec) {
  EXPECT_EQ(base_printf("Hello, %x!\n", 1024), 12);
  EXPECT_EQ(buf_, "Hello, 400!\n");
}

TEST_F(PrintfTest, HexFromDecWithWidth) {
  EXPECT_EQ(base_printf("Hello, %08x!\n", 1024), 17);
  EXPECT_EQ(buf_, "Hello, 00000400!\n");
}

TEST_F(PrintfTest, HexLower) {
  EXPECT_EQ(base_printf("Hello, %x!\n", 0xdead'beef), 17);
  EXPECT_EQ(buf_, "Hello, deadbeef!\n");
}

TEST_F(PrintfTest, HexUpper) {
  EXPECT_EQ(base_printf("Hello, %X!\n", 0xdead'beef), 17);
  EXPECT_EQ(buf_, "Hello, DEADBEEF!\n");
}

TEST_F(PrintfTest, HexNegative) {
  EXPECT_EQ(base_printf("Hello, %x!\n", -1), 17);
  EXPECT_EQ(buf_, "Hello, ffffffff!\n");
}

TEST_F(PrintfTest, HexSvLower) {
  EXPECT_EQ(base_printf("Hello, %h!\n", 0xdead'beef), 17);
  EXPECT_EQ(buf_, "Hello, deadbeef!\n");
}

TEST_F(PrintfTest, HexSvUpper) {
  EXPECT_EQ(base_printf("Hello, %H!\n", 0xdead'beef), 17);
  EXPECT_EQ(buf_, "Hello, DEADBEEF!\n");
}

TEST_F(PrintfTest, Pointer) {
  auto *ptr = reinterpret_cast<uint32_t *>(0x1234);
  base_printf("Hello, %p!\n", ptr);
  switch (sizeof(uintptr_t)) {
    case 4:
      EXPECT_EQ(buf_, "Hello, 0x00001234!\n");
      break;
    case 8:
      EXPECT_EQ(buf_, "Hello, 0x0000000000001234!\n");
      break;
    default:
      FAIL() << "Unknown pointer size";
      break;
  }
}

TEST_F(PrintfTest, NullPtr) {
  base_printf("Hello, %p!\n", nullptr);
  switch (sizeof(uintptr_t)) {
    case 4:
      EXPECT_EQ(buf_, "Hello, 0x00000000!\n");
      break;
    case 8:
      EXPECT_EQ(buf_, "Hello, 0x0000000000000000!\n");
      break;
    default:
      FAIL() << "Unknown pointer size";
      break;
  }
}

TEST_F(PrintfTest, Octal) {
  EXPECT_EQ(base_printf("Hello, %o!\n", 01234567), 16);
  EXPECT_EQ(buf_, "Hello, 1234567!\n");
}

TEST_F(PrintfTest, Binary) {
  EXPECT_EQ(base_printf("Hello, %b!\n", 0b1010'1010), 17);
  EXPECT_EQ(buf_, "Hello, 10101010!\n");
}

TEST_F(PrintfTest, BinaryWithWidth) {
  EXPECT_EQ(base_printf("Hello, %032b!\n", 0b1010'1010), 41);
  EXPECT_EQ(buf_, "Hello, 00000000000000000000000010101010!\n");
}

TEST_F(PrintfTest, StatusOk) {
  status_t value = OK_STATUS();
  EXPECT_EQ(base_printf("Hello, %r\n", value), 12);
  EXPECT_EQ(buf_, "Hello, Ok:0\n");
}

TEST_F(PrintfTest, StatusOkWithArg) {
  status_t value = OK_STATUS(12345);
  EXPECT_EQ(base_printf("Hello, %r\n", value), 16);
  EXPECT_EQ(buf_, "Hello, Ok:12345\n");
}

TEST_F(PrintfTest, StatusError) {
  status_t value = UNKNOWN();
  int line = __LINE__ - 1;
  EXPECT_EQ(base_printf("Hello, %r\n", value), 27);
  EXPECT_EQ(buf_, absl::StrFormat("Hello, Unknown:[\"PRI\",%d]\n", line));
}

TEST_F(PrintfTest, StatusErrorAsJson) {
  status_t value = UNKNOWN();
  int line = __LINE__ - 1;
  EXPECT_EQ(base_printf("Hello, %!r\n", value), 31);
  EXPECT_EQ(buf_, absl::StrFormat("Hello, {\"Unknown\":[\"PRI\",%d]}\n", line));
}

TEST_F(PrintfTest, StatusErrorWithModuleId) {
#define MODULE_ID MAKE_MODULE_ID('\\', '\\', '\\')
  status_t value = UNKNOWN();
  int line = __LINE__ - 1;
  EXPECT_EQ(base_printf("Hello, %!r\n", value), 34);
  EXPECT_EQ(buf_, absl::StrFormat(
                      "Hello, {\"Unknown\":[\"\\\\\\\\\\\\\",%d]}\n", line));
#undef MODULE_ID
}

TEST_F(PrintfTest, StatusErrorWithArg) {
  status_t value = INVALID_ARGUMENT(2);
  EXPECT_EQ(base_printf("Hello, %r\n", value), 33);
  EXPECT_EQ(buf_, absl::StrFormat("Hello, InvalidArgument:[\"PRI\",%d]\n", 2));
}

TEST_F(PrintfTest, FourCharacterCode) {
  EXPECT_EQ(base_printf("Hello, %C\n", 0x5CA245D3), 18);
  EXPECT_EQ(buf_, "Hello, \\xd3E\\xa2\\\n");
}

TEST_F(PrintfTest, FourCharacterCodePrintable) {
  EXPECT_EQ(base_printf("Hello, %C\n", 0x65766144), 12);
  EXPECT_EQ(buf_, "Hello, Dave\n");
}

TEST_F(PrintfTest, FourCharacterCodeNonPrintable) {
  EXPECT_EQ(base_printf("Hello, %C\n", 0xAABBCCDD), 24);
  EXPECT_EQ(buf_, "Hello, \\xdd\\xcc\\xbb\\xaa\n");
}

TEST_F(PrintfTest, IncompleteSpec) {
  base_printf("Hello, %");
  EXPECT_THAT(buf_, StartsWith("Hello, "));
}

TEST_F(PrintfTest, UnknownSpec) {
  base_printf("Hello, %j");
  EXPECT_THAT(buf_, StartsWith("Hello, "));
}

TEST_F(PrintfTest, WidthTooNarrow) {
  base_printf("Hello, %0x");
  EXPECT_THAT(buf_, StartsWith("Hello, "));
}

TEST_F(PrintfTest, WidthTooWide) {
  base_printf("Hello, %9001x");
  EXPECT_THAT(buf_, StartsWith("Hello, "));
}

TEST_F(PrintfTest, ManySpecifiers) {
  base_printf("%d + %d == %d, also spelled 0x%x", 2, 8, 2 + 8, 2 + 8);
  EXPECT_THAT(buf_, StartsWith("2 + 8 == 10, also spelled 0xa"));
}

TEST_F(PrintfTest, HexDump) {
  constexpr char kStuff[] =
      "a very long string pot\x12\x02\xAA entially containing garbage";
  base_hexdump(kStuff, sizeof(kStuff) - 1);
  EXPECT_THAT(
      buf_,
      R"hex(00000000: 6120 7665 7279 206c 6f6e 6720 7374 7269  a very long stri
00000010: 6e67 2070 6f74 1202 aa20 656e 7469 616c  ng pot... ential
00000020: 6c79 2063 6f6e 7461 696e 696e 6720 6761  ly containing ga
00000030: 7262 6167 65                             rbage
)hex");

  buf_.clear();
  base_hexdump_with({3, 5, &kBaseHexdumpDefaultFmtAlphabet}, kStuff,
                    sizeof(kStuff) - 1);
  EXPECT_THAT(
      buf_, R"hex(00000000: 612076 657279 206c6f 6e6720 737472  a very long str
0000000f: 696e67 20706f 741202 aa2065 6e7469  ing pot... enti
0000001e: 616c6c 792063 6f6e74 61696e 696e67  ally containing
0000002d: 206761 726261 6765                   garbage
)hex");
}

TEST(SnprintfTest, SimpleWrite) {
  std::string buf(128, '\0');
  auto len = base_snprintf(&buf[0], buf.size(), "Hello, World!\n");
  buf.resize(len);
  EXPECT_EQ(len, 14);
  EXPECT_EQ(buf, "Hello, World!\n");
}

TEST(SnprintfTest, ComplexFormating) {
  std::string buf(128, '\0');
  auto len =
      base_snprintf(&buf[0], buf.size(), "%d + %d == %d, also spelled 0x%x", 2,
                    8, 2 + 8, 2 + 8);
  buf.resize(len);
  EXPECT_EQ(buf, "2 + 8 == 10, also spelled 0xa");
}

TEST(SnprintfTest, PartialWrite) {
  std::string buf(16, '\0');
  auto len =
      base_snprintf(&buf[0], buf.size(), "%d + %d == %d, also spelled 0x%x", 2,
                    8, 2 + 8, 2 + 8);
  buf.resize(len);
  EXPECT_EQ(len, 16);
  EXPECT_EQ(buf, "2 + 8 == 10, als");
}

}  // namespace
}  // namespace base

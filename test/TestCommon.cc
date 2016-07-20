/*
 The MIT License (MIT)

 Copyright (c) [2016] [BTC.COM]

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */

#include "gtest/gtest.h"
#include "Common.h"
#include "Utils.h"


TEST(Common, score2Str) {
  // 10e-25
  ASSERT_EQ(score2Str(0.0000000000000000000000001), "0.0000000000000000000000001");
  ASSERT_EQ(score2Str(0.0000000000000000000000009), "0.0000000000000000000000009");
  ASSERT_EQ(score2Str(0.000000000000000000000001),  "0.0000000000000000000000010");
  ASSERT_EQ(score2Str(0.00000000000000000000001),   "0.0000000000000000000000100");
  ASSERT_EQ(score2Str(0.0000000000000000000001),    "0.0000000000000000000001000");
  ASSERT_EQ(score2Str(0.000000000000000000001), "0.0000000000000000000010000");
  ASSERT_EQ(score2Str(0.00000000000000000001),  "0.0000000000000000000100000");
  ASSERT_EQ(score2Str(0.0000000000000000001),   "0.0000000000000000001000000");
  ASSERT_EQ(score2Str(0.000000000000000001),    "0.0000000000000000010000000");
  ASSERT_EQ(score2Str(0.00000000000000001), "0.0000000000000000100000000");
  ASSERT_EQ(score2Str(0.0000000000000001),  "0.0000000000000001000000000");
  ASSERT_EQ(score2Str(0.000000000000001),   "0.0000000000000010000000000");
  ASSERT_EQ(score2Str(0.00000000000001),    "0.0000000000000100000000000");
  ASSERT_EQ(score2Str(0.0000000000001), "0.0000000000001000000000000");
  ASSERT_EQ(score2Str(0.000000000001),  "0.0000000000010000000000000");
  ASSERT_EQ(score2Str(0.00000000001),   "0.0000000000100000000000000");

  ASSERT_EQ(score2Str(0.0000000001),    "0.000000000100000000000000");
  ASSERT_EQ(score2Str(0.000000001), "0.00000000100000000000000");
  ASSERT_EQ(score2Str(0.00000001),  "0.0000000100000000000000");
  ASSERT_EQ(score2Str(0.0000001),   "0.000000100000000000000");
  ASSERT_EQ(score2Str(0.000001),    "0.00000100000000000000");
  ASSERT_EQ(score2Str(0.00001), "0.0000100000000000000");
  ASSERT_EQ(score2Str(0.0001),  "0.000100000000000000");
  ASSERT_EQ(score2Str(0.001),   "0.00100000000000000");
  ASSERT_EQ(score2Str(0.01),    "0.0100000000000000");
  ASSERT_EQ(score2Str(0.1), "0.100000000000000");
  ASSERT_EQ(score2Str(1.0), "1.00000000000000");
  ASSERT_EQ(score2Str(10.0),    "10.0000000000000");
  ASSERT_EQ(score2Str(100.0),   "100.000000000000");
  ASSERT_EQ(score2Str(1000.0),  "1000.00000000000");
  ASSERT_EQ(score2Str(10000.0), "10000.0000000000");
  ASSERT_EQ(score2Str(100000.0),    "100000.000000000");
  ASSERT_EQ(score2Str(1000000.0),   "1000000.00000000");
  ASSERT_EQ(score2Str(10000000.0),  "10000000.0000000");
  ASSERT_EQ(score2Str(100000000.0), "100000000.000000");

  ASSERT_EQ(score2Str(123412345678.0), "123412345678.00");
  ASSERT_EQ(score2Str(1234.12345678123), "1234.1234567812");
}

TEST(Common, BitsToTarget) {
  uint32 bits;
  uint256 target;

  bits = 0x1b0404cb;
  BitsToTarget(bits, target);
  ASSERT_EQ(target, uint256("00000000000404CB000000000000000000000000000000000000000000000000"));
}

TEST(Common, TargetToBdiff) {
  // 0x00000000FFFF0000000000000000000000000000000000000000000000000000 /
  // 0x00000000000404CB000000000000000000000000000000000000000000000000
  // = 16307.420938523983 (bdiff)
  ASSERT_EQ(TargetToBdiff("0x00000000000404CB000000000000000000000000000000000000000000000000"), 16307);
}


TEST(Common, TargetToPdiff) {
  // 0x00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF /
  // 0x00000000000404CB000000000000000000000000000000000000000000000000
  // = 16307.669773817162 (pdiff)
  ASSERT_EQ(TargetToBdiff("0x00000000000404CB000000000000000000000000000000000000000000000000"), 16307);
}

#include "stdafx.h"
#include "Fraction.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
TEST(FractionTest, GCD_LCM_Test) {
  ASSERT_EQ(Fraction::GCD(0, 0), 0);
  ASSERT_EQ(Fraction::GCD(0, 5), 0);
  ASSERT_EQ(Fraction::GCD(1, 0), 0);
  ASSERT_EQ(Fraction::GCD(1, 3), 1);
  ASSERT_EQ(Fraction::GCD(8, 2), 2);
  ASSERT_EQ(Fraction::GCD(12, 9), 3);
  ASSERT_EQ(Fraction::LCM(0, 0), 0);
  ASSERT_EQ(Fraction::LCM(0, 5), 0);
  ASSERT_EQ(Fraction::LCM(1, 0), 0);
  ASSERT_EQ(Fraction::LCM(1, 3), 3);
  ASSERT_EQ(Fraction::LCM(8, 2), 8);
  ASSERT_EQ(Fraction::LCM(3, 2), 6);
  ASSERT_EQ(Fraction::LCM(12, 9), 36);
}

TEST(FractionTest, CreationTest) {
  Fraction f1(8, 2), f2(-9, 3), f3(4, -5);
  ASSERT_EQ(f1.ToString(), "4");
  ASSERT_EQ(f2.ToString(), "-3");
  ASSERT_EQ(f3.ToString(), "-4|5");
  try {
    Fraction f4(2, 0);
    ASSERT_FALSE("should throw exception");
  }
  catch (std::exception & e) {
    ASSERT_TRUE(e.what());
  }
}

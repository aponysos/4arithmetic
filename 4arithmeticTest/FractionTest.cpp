#include "stdafx.h"
#include "Fraction.h"
#include "Expression.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(FractionTest, CreationTest) {
  Fraction f0, f1(6, 2), f2(-10, 4), f3(4, -6);
  ASSERT_EQ(f0.GetNumerator(), 0);
  ASSERT_EQ(f0.GetDenominator(), 1);
  ASSERT_EQ(f1.GetNumerator(), 3);
  ASSERT_EQ(f1.GetDenominator(), 1);
  ASSERT_EQ(f2.GetNumerator(), -5);
  ASSERT_EQ(f2.GetDenominator(), 2);
  ASSERT_EQ(f3.GetNumerator(), -2);
  ASSERT_EQ(f3.GetDenominator(), 3);
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

TEST(FractionTest, ToStringTest) {
  Fraction f0, f1(8, 2), f2(-9, 3), f3(4, -5);
  ASSERT_EQ(f0.ToString(), "0");
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

TEST(FractionTest, FromStringTest) {
  Fraction f0("10|5");
  ASSERT_EQ(f0.GetNumerator(), 2);
  ASSERT_EQ(f0.GetDenominator(), 1);
  Fraction f1("10|-5");
  ASSERT_EQ(f1.GetNumerator(), -2);
  ASSERT_EQ(f1.GetDenominator(), 1);
}

TEST(FractionTest, OperatorTest) {
  ASSERT_EQ(Fraction("1|2"), Fraction(2, 4));
  ASSERT_EQ(Fraction("1|2") + Fraction(1, 4), Fraction("6|8"));
  ASSERT_EQ(Fraction("1|2") - Fraction(1, 4), Fraction(2, 8));
  ASSERT_EQ(Fraction("3|4") * Fraction(2, 5), Fraction(3, 10));
  ASSERT_EQ(Fraction(7, 12) / Fraction(8, 6), Fraction(7, 16));
}

TEST(ExpressionTest, EvaluateTest) {
  auto e1 = new PlusExpression(
    new ValueExpression(Fraction("1|5")), new ValueExpression(Fraction("1|4"))
  );
  ASSERT_EQ(e1->Evaluate(), Fraction("9|20"));
  delete e1;
}

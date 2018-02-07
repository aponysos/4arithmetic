#include "stdafx.h"
#include "Fraction.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(FractionTest, CreationTest) {
  Fraction f1(8, 2), f2(-9, 3), f3(4, -5);
  ASSERT_EQ(f1.ToString(), "4");
  ASSERT_EQ(f2.ToString(), "-3");
  ASSERT_EQ(f3.ToString(), "4|-5");
  try {
    Fraction f4(2, 0);
    ASSERT_FALSE("should throw exception");
  }
  catch (std::exception & e) {
    ASSERT_TRUE(e.what());
  }
}

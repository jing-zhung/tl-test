#include <gtest/gtest.h>
#include "binary_tree_calculator.hpp"

TEST(BinaryTreeCalculatorTest, BasicAssertions)
{
    BinaryTreeCalculator calc;
    calc.setInput("(1 + 1) * 2");
    EXPECT_EQ(calc.getAnswer(), 4);
    calc.reset();

    calc.setInput("((15 / (7 - (1 + 1) ) ) * -3 ) - (2 + (1 + 1))");
    EXPECT_EQ(calc.getAnswer(), -13);
    calc.reset();
}
#include <gtest/gtest.h>

#include <formatter.h>
#include <solver.h>

#include <string>

TEST(Formatter, FormatString)
{
    std::string result = formatter("hello");

    EXPECT_FALSE(result.empty());
}

TEST(Solver, QuadraticEquation)
{
    double result = solve(1, -2, 1);

    EXPECT_DOUBLE_EQ(result, 1);
}

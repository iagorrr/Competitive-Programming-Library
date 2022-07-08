#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Math/Extended Euclidian algorithm.cpp"
#include "../../content/Math/Linear diophantine equation (solve).cpp"

const int MX = 100;

void check(int a, int b, int c) {
    auto res = diophantineEquationSolution(a, b, c);

    if (a == 0 and b == 0) {
        if (c) {
            ASSERT_FALSE(res.has_value());
        } else {
            ASSERT_TRUE(res.has_value());
        }
        return;
    }

    auto gcd_a_b = get<0>(extGcd(a, b));

    if (c % gcd_a_b)  // no solution
        ASSERT_EQ(res, nullopt);
    else  // yes solution : D
        ASSERT_TRUE(res.has_value());

    if (res) {
        auto [x, y] = *res;
        EXPECT_EQ(a * x + b * y, c);
    }
}

TEST(LinearDiophantineEquationSolveTest, BruteForce) {
    rep(a, -MX, MX + 1) {
        rep(b, -MX, MX + 1) {
            rep(c, -MX, MX + 1) { check(a, b, c); }
        }
    }
}

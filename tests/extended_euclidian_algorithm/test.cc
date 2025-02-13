#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Math/Extended Euclidian algorithm.cpp"

const int MX = 100;

TEST(ExtendedEuclidianAlgorithmTest, BruteForce) {
    rep(a, -MX, MX + 1) {
        rep(b, -MX, MX + 1) {
            auto [g, x, y] = extGcd(a, b);
            EXPECT_EQ(a * x + b * y, g);
        }
    }
}

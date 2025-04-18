#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Strings/Z-Function/z-function-build.cpp"

// Test case 1: Simple test case
TEST(ZFunctionTest, SimpleTest) {
    std::string s = "aabcaabxaaaz";
    std::vector<int> expected = {0, 1, 0, 0, 3, 1, 0, 0, 2, 2, 1, 0};
    std::vector<int> result = z_function_build(s);
    EXPECT_EQ(result, expected);
}

// Test case 2: Empty string
TEST(ZFunctionTest, EmptyString) {
    std::string s = "";
    std::vector<int> expected = {};
    std::vector<int> result = z_function_build(s);
    EXPECT_EQ(result, expected);
}

// Test case 3: String with no repeated patterns
TEST(ZFunctionTest, NoRepeats) {
    std::string s = "abcdef";
    std::vector<int> expected = {0, 0, 0, 0, 0, 0};
    std::vector<int> result = z_function_build(s);
    EXPECT_EQ(result, expected);
}

// Test case 4: String where the entire string is a repeat
TEST(ZFunctionTest, WholeStringRepeat) {
    std::string s = "zzzzzz";
    std::vector<int> expected = {0, 5, 4, 3, 2, 1};
    std::vector<int> result = z_function_build(s);
    EXPECT_EQ(result, expected);
}

// Test case 5: Single character string
TEST(ZFunctionTest, SingleCharacter) {
    std::string s = "a";
    std::vector<int> expected = {0};
    std::vector<int> result = z_function_build(s);
    EXPECT_EQ(result, expected);
}

// Test case 6: Edge case - very large string
TEST(ZFunctionTest, LargeString) {
    std::string s = string(10000, 'a') + "b";
    std::vector<int> result = z_function_build(s);
    EXPECT_EQ(result[0], 0);      // First value should always be 0
    EXPECT_EQ(result.back(), 0);  // The large part should give z-function of 0
}

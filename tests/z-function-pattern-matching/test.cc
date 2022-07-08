#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Strings/Z-Function/z-function-pattern-matching.cpp"

TEST(PatternMatchingTest, SimpleTest) {
    std::string text = "abacabadabacaba";
    std::string pattern = "abac";
    std::vector<int> expected = {0, 8};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, NoMatch) {
    std::string text = "abcdef";
    std::string pattern = "gh";
    std::vector<int> expected = {};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, MultipleMatches) {
    std::string text = "abababab";
    std::string pattern = "ab";
    std::vector<int> expected = {0, 2, 4, 6};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, SingleCharacterPattern) {
    std::string text = "aaaaaa";
    std::string pattern = "a";
    std::vector<int> expected = {0, 1, 2, 3, 4, 5};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, PatternLargerThanText) {
    std::string text = "ab";
    std::string pattern = "abcd";
    std::vector<int> expected = {};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, EdgeCaseEmptyPattern) {
    std::string text = "abcd";
    std::string pattern = "";
    std::vector<int> expected = {};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, EdgeCaseEmptyText) {
    std::string text = "";
    std::string pattern = "abc";
    std::vector<int> expected = {};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, EdgeCaseEmptyTextAndPattern) {
    std::string text = "";
    std::string pattern = "";
    std::vector<int> expected = {};
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, LargeTextWithNoMatches) {
    std::string text = string(10000, 'a');
    std::string pattern = "b";
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    std::vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST(PatternMatchingTest, LargeTextWithMatches) {
    std::string text = string(10000, 'a') + "b" + string(10000, 'a');
    std::string pattern = "b";
    std::vector<int> result = z_function_pattern_matching(text, pattern);
    std::vector<int> expected = {10000};
    EXPECT_EQ(result, expected);
}

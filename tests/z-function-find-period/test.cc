#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Strings/Z-Function/z-function-find-period.cpp"

TEST(ZFunctionFindPeriodTest, SimpleRepeatingString) {
    std::string s("ababab");
    int result = z_function_find_period(s);
    EXPECT_EQ(result, 2);  // "ab" is the repeating unit
}

TEST(ZFunctionFindPeriodTest, FullRepetition) {
    std::string s = "aaaaaa";
    int result = z_function_find_period(s);
    EXPECT_EQ(result, 1);  // one character repeated
}

TEST(ZFunctionFindPeriodTest, NoRepetition) {
    std::string s = "abcdef";
    int result = z_function_find_period(s);
    EXPECT_EQ(result, 6);  // entire string is the period
}

TEST(ZFunctionFindPeriodTest, PartialRepetition) {
    std::string s = "abcab";
    int result = z_function_find_period(s);
    EXPECT_EQ(result, 5);  // not fully periodic
}

TEST(ZFunctionFindPeriodTest, OneCharacter) {
    std::string s = "a";
    int result = z_function_find_period(s);
    EXPECT_EQ(result, 1);  // single char is its own period
}

TEST(ZFunctionFindPeriodTest, EmptyString) {
    std::string s = "";
    int result = z_function_find_period(s);
    EXPECT_EQ(result, 0);  // edge case: empty string
}

TEST(ZFunctionFindPeriodTest, IntegerSequenceRepeating) {
    std::vector<int> v = {1, 2, 3, 1, 2, 3};
    int result = z_function_find_period(v);
    EXPECT_EQ(result, 3);  // "1 2 3" repeated
}

TEST(ZFunctionFindPeriodTest, IntegerSequenceNoRepetition) {
    std::vector<int> v = {1, 2, 3, 4};
    int result = z_function_find_period(v);
    EXPECT_EQ(result, 4);  // no repeating prefix
}

TEST(ZFunctionFindPeriodTest, IntegerSequenceSingleElement) {
    std::vector<int> v = {9};
    int result = z_function_find_period(v);
    EXPECT_EQ(result, 1);  // single element
}

TEST(ZFunctionFindPeriodTest, IntegerSequenceAllSame) {
    std::vector<int> v = {5, 5, 5, 5, 5};
    int result = z_function_find_period(v);
    EXPECT_EQ(result, 1);  // all identical
}

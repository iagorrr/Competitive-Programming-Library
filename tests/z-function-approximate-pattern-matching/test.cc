#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Strings/Z-Function/z-function-approximate-pattern-matching.cpp"

TEST(ApproximatePatternMatchingTest, ExactMatchK0) {
    std::string text = "abacabadabacaba";
    std::string pattern = "abac";
    std::vector<int> expected = {0, 8};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 0);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, MatchWithOneError) {
    std::string text = "abacabadabacaba";
    std::string pattern = "abac";
    std::vector<int> expected = {0, 4, 8};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 1);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, NoMatchEvenWithErrors) {
    std::string text = "abcdef";
    std::string pattern = "gh";
    std::vector<int> expected = {};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 1);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, AllMatchWithHighK) {
    std::string text = "abcdefgh";
    std::string pattern = "abc";
    std::vector<int> expected = {0, 1, 2, 3, 4, 5};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 3);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, SingleCharacterPattern) {
    std::string text = "aaaaaa";
    std::string pattern = "a";
    std::vector<int> expected = {0, 1, 2, 3, 4, 5};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 0);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, PatternLargerThanText) {
    std::string text = "ab";
    std::string pattern = "abcd";
    std::vector<int> expected = {};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 1);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, EdgeCaseEmptyPattern) {
    std::string text = "abcd";
    std::string pattern = "";
    std::vector<int> expected = {};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 1);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, EdgeCaseEmptyText) {
    std::string text = "";
    std::string pattern = "abc";
    std::vector<int> expected = {};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 1);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, EdgeCaseEmptyTextAndPattern) {
    std::string text = "";
    std::string pattern = "";
    std::vector<int> expected = {};
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 0);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, LargeTextWithNoMatchesEvenWithErrors) {
    std::string text = std::string(10000, 'a');
    std::string pattern = "bbbb";
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 2);
    std::vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, MatchWithMaxAllowedMismatches) {
    std::string text = "abcdeabcdeabcde";
    std::string pattern = "abcde";

    // Aqui a gente insere versões com até 4 erros (num padrão de tamanho 5)
    // Exemplos: "abzde", "xbcde", "abcxe", etc.
    std::string noisy_text =
        "abzde"
        "xbcde"
        "abcxe"
        "abcue"
        "abcdf";  // 5 versões com 1 erro cada
    std::vector<int> expected = {0, 5, 10, 15, 20};

    std::vector<int> result =
        z_function_approximate_pattern_matching(noisy_text, pattern, 1);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, MatchWithFourMismatchesAllowed) {
    std::string text = "zzzzz";
    std::string pattern = "abcde";  // totalmente diferente
    // São 5 chars totalmente diferentes → 5 mismatches
    // Mas com k=4, não deveria aceitar
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 4);
    std::vector<int> expected = {};
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, FullMismatchButAllowed) {
    std::string text = "vwxyz";
    std::string pattern = "abcde";  // 5 mismatches, exatamente igual a k
    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 5);
    std::vector<int> expected = {0};
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, HighMismatchInLongText) {
    std::string pattern = "algorithm";
    std::string match = "algoXXthm";

    std::string text = std::string(100, 'z') + match + std::string(100, 'z');
    std::vector<int> expected = {100};

    std::vector<int> result =
        z_function_approximate_pattern_matching(text, pattern, 2);
    EXPECT_EQ(result, expected);
}

TEST(ApproximatePatternMatchingTest, RepeatedPatternWithIncreasingErrors) {
    std::string base = "abcde";
    std::vector<std::string> noisy_versions = {
        "abcde",  // 0 errors
        "abcdd",  // 1 error
        "abccd",  // 2 errors
        "abccd",  // 2 errors
        "abccd",  // 2 errors
        "abccd",  // 2 errors
        "abccd"   // 2 errors
    };
    std::string text;
    for (auto& v : noisy_versions) text += v;

    std::vector<int> expected = {0, 5, 10, 15, 20, 25, 30};

    std::vector<int> result =
        z_function_approximate_pattern_matching(text, base, 2);
    EXPECT_EQ(result, expected);
}

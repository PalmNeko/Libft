
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strmatch, Basic) {
    EXPECT_TRUE(ft_strmatch("abc", "abc"));
}

// Dot test
TEST(ft_strmatch, Dot) {
    EXPECT_TRUE(ft_strmatch("a.c", "abc"));
    EXPECT_FALSE(ft_strmatch("a.c.", "abc"));
}

// Question test
TEST(ft_strmatch, Question) {
    EXPECT_TRUE(ft_strmatch("a.?.?.?bc", "abc"));
    EXPECT_TRUE(ft_strmatch("ab?c", "abc"));
    EXPECT_TRUE(ft_strmatch("a.?c", "abc"));
    EXPECT_TRUE(ft_strmatch("a.c?", "abc"));
    EXPECT_TRUE(ft_strmatch("a.c?", "ab"));
    EXPECT_TRUE(ft_strmatch("a.c?", "ac"));
    EXPECT_TRUE(ft_strmatch("https?", "http"));
    EXPECT_TRUE(ft_strmatch("https?", "https"));
    EXPECT_FALSE(ft_strmatch("https?$", "httpf"));
}

// Asterisk test
TEST(ft_strmatch, Asterisk) {
    EXPECT_TRUE(ft_strmatch(".*", "acasdf"));
    EXPECT_TRUE(ft_strmatch(".*abcdef", "abcdef"));
    EXPECT_TRUE(ft_strmatch(".*def", "abcdef"));
    EXPECT_TRUE(ft_strmatch(".*.*.*", "abcdef"));
    EXPECT_TRUE(ft_strmatch("a.*", "abcdef"));
    EXPECT_FALSE(ft_strmatch(".*e$", "abcdef"));
    EXPECT_FALSE(ft_strmatch("^b.*", "abcdef"));
    EXPECT_TRUE(ft_strmatch("\\*?.", "*a"));
}

// Plus test
TEST(ft_strmatch, Plus) {
    EXPECT_TRUE(ft_strmatch("b+", ":bbbbbb"));
    EXPECT_TRUE(ft_strmatch("b+c", ":bc"));
    EXPECT_TRUE(ft_strmatch("b+c+d", ":bcccddd"));
    EXPECT_FALSE(ft_strmatch("b+c", "c"));
}

// Caret test
TEST(ft_strmatch, Caret) {
    EXPECT_TRUE(ft_strmatch("^bc", "bc"));
    EXPECT_FALSE(ft_strmatch("^bc", "abc"));
    EXPECT_FALSE(ft_strmatch("^^bc", "^bc"));
}

// Dollar test
TEST(ft_strmatch, Dollar) {
    EXPECT_TRUE(ft_strmatch("abc$", "abc"));
    EXPECT_FALSE(ft_strmatch("abc$", "abcabb"));
    EXPECT_FALSE(ft_strmatch("abc$a", "abc"));
    EXPECT_FALSE(ft_strmatch("$abc", "abc"));
}

// Escape test
TEST(ft_strmatch, Escape) {
    EXPECT_TRUE(ft_strmatch("\\.txt", "sample.txt"));
    EXPECT_TRUE(ft_strmatch("\\.txt$", "sample.txt"));
    EXPECT_FALSE(ft_strmatch("\\.txt$", "sampleatxta"));
    EXPECT_TRUE(ft_strmatch("txt\\$", "sample.txt$"));
    EXPECT_FALSE(ft_strmatch("txt\\$", "sample.txt"));
}

// Additional tests for end of string
TEST(ft_strmatch, EndOfString) {
    EXPECT_TRUE(ft_strmatch("abc$", "abc"));
    EXPECT_FALSE(ft_strmatch("abc$", "abcabb"));
    EXPECT_FALSE(ft_strmatch("abc$a", "abc"));
    EXPECT_FALSE(ft_strmatch("$abc", "abc"));
}

// Additional tests for start of string
TEST(ft_strmatch, StartOfString) {
    EXPECT_TRUE(ft_strmatch("^abc", "abc"));
    EXPECT_FALSE(ft_strmatch("^abc", "aabc"));
    EXPECT_FALSE(ft_strmatch("a^bc", "abc"));
}

// Additional tests for any single character
TEST(ft_strmatch, AnySingleCharacter) {
    EXPECT_TRUE(ft_strmatch("a.c", "abc"));
    EXPECT_TRUE(ft_strmatch("a.c", "axc"));
    EXPECT_FALSE(ft_strmatch("a.c", "ac"));
    EXPECT_FALSE(ft_strmatch("a.c", "abxc"));
}

// Additional tests for zero or more occurrences
TEST(ft_strmatch, ZeroOrMoreOccurrences) {
    EXPECT_TRUE(ft_strmatch("ab*c", "ac"));
    EXPECT_TRUE(ft_strmatch("ab*c", "abc"));
    EXPECT_TRUE(ft_strmatch("ab*c", "abbc"));
    EXPECT_TRUE(ft_strmatch("ab*c", "abbbbc"));
    EXPECT_TRUE(ft_strmatch("ab*c", "abbbcabc"));
}

// Additional tests for one or more occurrences
TEST(ft_strmatch, OneOrMoreOccurrences) {
    EXPECT_TRUE(ft_strmatch("ab+c", "abc"));
    EXPECT_TRUE(ft_strmatch("ab+c", "abbc"));
    EXPECT_TRUE(ft_strmatch("ab+c", "abbbbc"));
    EXPECT_FALSE(ft_strmatch("ab+c", "ac"));
}

// Additional tests for zero or one occurrence
TEST(ft_strmatch, ZeroOrOneOccurrence) {
    EXPECT_TRUE(ft_strmatch("ab?c", "ac"));
    EXPECT_TRUE(ft_strmatch("ab?c", "abc"));
    EXPECT_FALSE(ft_strmatch("ab?c", "abbc"));
}

// Additional tests combining multiple regex features
TEST(ft_strmatch, CombinedRegexFeatures) {
    EXPECT_TRUE(ft_strmatch("^a.b+c$", "axbc"));
    EXPECT_TRUE(ft_strmatch("^a.bc+$", "axbcccc"));
    EXPECT_FALSE(ft_strmatch("^a.b+c$", "aabcccc"));
    EXPECT_FALSE(ft_strmatch("^a.b+c$", "axcc"));
}

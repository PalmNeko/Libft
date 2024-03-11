
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strlcpy, basic_usage) {
	char	dst[30];
	char	*src = "abcdef";

	EXPECT_EQ((size_t)6, ft_strlcpy(dst, "abcdef", 30));
	ASSERT_NE(src, dst);
	EXPECT_STREQ(src, dst);
	EXPECT_EQ((size_t)0, ft_strlcpy(dst, "", 30));
	EXPECT_STREQ("", dst);
	EXPECT_EQ((size_t)1, ft_strlcpy(dst, "a", 30));
	EXPECT_STREQ("a", dst);
	EXPECT_EQ((size_t)6, ft_strlcpy(dst, "abcdef", 6));
	EXPECT_STREQ("abcde", dst);
	EXPECT_EQ((size_t)0, ft_strlcpy(dst, "", 1));
	EXPECT_STREQ("", dst);
	EXPECT_EQ((size_t)1, ft_strlcpy(dst, "a", 30));
	EXPECT_STREQ("a", dst);
	EXPECT_EQ((size_t)6, ft_strlcpy(dst, "abcdef", 0));
	EXPECT_STREQ("a", dst);
}

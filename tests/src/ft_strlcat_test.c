
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strlcat, basic_usage) {
	char	str[30] = "";

	EXPECT_EQ((size_t)3, ft_strlcat(str, "abc", 30));
	EXPECT_STREQ("abc", str);
	EXPECT_EQ((size_t)6, ft_strlcat(str, "def", 30));
	EXPECT_STREQ("abcdef", str);
	EXPECT_EQ((size_t)9, ft_strlcat(str, "ghi", 7));
	EXPECT_STREQ("abcdef", str);
	EXPECT_EQ((size_t)9, ft_strlcat(str, "ghi", 9));
	EXPECT_STREQ("abcdefgh", str);
	EXPECT_EQ((size_t)9, ft_strlcat(str, "i", 10));
	EXPECT_STREQ("abcdefghi", str);
}

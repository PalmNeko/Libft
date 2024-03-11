
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strchr, basic_usage) {
	char	src[] = "abcdefgh";

	EXPECT_EQ(src, ft_strchr(src, 'a'));
	EXPECT_EQ(NULL, ft_strchr(src, 'z'));
	EXPECT_EQ(src + 7, ft_strchr(src, 'h'));
	EXPECT_STREQ(src, "abcdefgh");
}

TEST(ft_strchr, boundary_value) {
	char	src[] = "abcdefgh";

	EXPECT_EQ(NULL, ft_strchr(src, 'i'));
	EXPECT_EQ(NULL, ft_strchr(src, 'a' - 1));
	EXPECT_STREQ(src, "abcdefgh");
}


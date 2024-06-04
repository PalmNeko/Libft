
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strcmp, basic_usage) {
	EXPECT_EQ(0, ft_strcmp("", ""));
	EXPECT_EQ(0, ft_strcmp("a", "a"));
	EXPECT_EQ(0, ft_strcmp("abc", "abc"));
	EXPECT_NE(0, ft_strcmp(" abc", "abc"));
	EXPECT_NE(0, ft_strcmp("abc ", "abc"));
	EXPECT_NE(0, ft_strcmp("abc", "abc "));
	EXPECT_NE(0, ft_strcmp("abc", " abc"));
	EXPECT_NE(0, ft_strcmp("abc", ""));
	EXPECT_NE(0, ft_strcmp("", " abc"));
}

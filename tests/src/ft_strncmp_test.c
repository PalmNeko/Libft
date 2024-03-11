
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strncmp, basic_usage) {
	EXPECT_EQ(0, ft_strncmp("", "", 0));
	EXPECT_EQ(0, ft_strncmp("", "", 1));
	EXPECT_EQ(0, ft_strncmp("abc", "abc", 3));
	EXPECT_EQ(0, ft_strncmp("abc", "abc", 4));
	EXPECT_EQ(0, ft_strncmp("abc", "abc", 3));
	EXPECT_LT(0, ft_strncmp("abd", "abc", 4));
	EXPECT_EQ(0, ft_strncmp("abc", "abd", 2));
}


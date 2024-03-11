
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strlen, basic_usage) {
	EXPECT_EQ((size_t)6, ft_strlen("abcdef"));
	EXPECT_EQ((size_t)3, ft_strlen("abc"));
	EXPECT_EQ((size_t)0, ft_strlen(""));
}


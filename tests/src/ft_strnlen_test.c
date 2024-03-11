
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strnlen, basic_usage) {
	EXPECT_EQ((size_t)0, ft_strnlen("", 3));
	EXPECT_EQ((size_t)3, ft_strnlen("abc", 5));
	EXPECT_EQ((size_t)3, ft_strnlen("abc", 3));
	EXPECT_EQ((size_t)2, ft_strnlen("abc", 2));
}

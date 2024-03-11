
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strnstr, basic_usage) {
	char	*src = "abcdef";

	EXPECT_EQ(NULL, ft_strnstr(src, "abd", 6));
	EXPECT_EQ(src, ft_strnstr(src, "abc", 6));
	EXPECT_EQ(NULL, ft_strnstr(src, "abc", 2));
	EXPECT_EQ(src, ft_strnstr(src, "abc", 3));
	EXPECT_EQ(NULL, ft_strnstr(src, "cdef", 2));
	EXPECT_EQ(src + 2, ft_strnstr(src, "cdef", 6));
	EXPECT_EQ(NULL, ft_strnstr(src, "cdef", 5));
}

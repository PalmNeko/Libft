
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_toupper, basic_usage) {
	EXPECT_EQ('A', ft_toupper('a'));
	EXPECT_EQ('Z', ft_toupper('z'));
	EXPECT_EQ('a' - 1, ft_toupper('a' - 1));
	EXPECT_EQ('z' + 1, ft_toupper('z' + 1));
}


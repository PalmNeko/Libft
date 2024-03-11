
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_tolower, basic_usage) {
	EXPECT_EQ('a', ft_tolower('A'));
	EXPECT_EQ('z', ft_tolower('Z'));
	EXPECT_EQ('A' - 1, ft_tolower('A' - 1));
	EXPECT_EQ('Z' + 1, ft_tolower('Z' + 1));
}

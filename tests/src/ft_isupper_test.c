
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_isupper, basic_usage) {
	EXPECT_NE(0, ft_isupper('A'));
	EXPECT_NE(0, ft_isupper('Z'));
	EXPECT_EQ(0, ft_isupper('A' - 1));
	EXPECT_EQ(0, ft_isupper('Z' + 1));
	EXPECT_EQ(0, ft_isupper('a'));
	EXPECT_EQ(0, ft_isupper('z'));
}

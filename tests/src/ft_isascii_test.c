
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_isascii, boundary_value) {
	EXPECT_NE(0, ft_isascii(0));
	EXPECT_NE(0, ft_isascii(0177));
	EXPECT_NE(0, ft_isascii(123));
	EXPECT_NE(0, ft_isascii(12));
	EXPECT_NE(0, ft_isascii(51));
	EXPECT_EQ(0, ft_isascii(0 - 1));
	EXPECT_EQ(0, ft_isascii(0177 + 1));
	EXPECT_EQ(0, ft_isascii(0 + 255));
	EXPECT_EQ(0, ft_isascii(0 + 128));
	EXPECT_EQ(0, ft_isascii(120 + 255));
	EXPECT_EQ(0, ft_isascii(120 + 128));
}


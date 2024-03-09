
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_isalpha, boundary_value) {
	EXPECT_NE(0, ft_isalnum('a'));
	EXPECT_NE(0, ft_isalnum('z'));
	EXPECT_NE(0, ft_isalnum('A'));
	EXPECT_NE(0, ft_isalnum('Z'));
	EXPECT_EQ(0, ft_isalnum('a' + 255));
	EXPECT_EQ(0, ft_isalnum('z' + 255));
	EXPECT_EQ(0, ft_isalnum('A' + 255));
	EXPECT_EQ(0, ft_isalnum('Z' + 255));
	EXPECT_EQ(0, ft_isalnum('a' - 1));
	EXPECT_EQ(0, ft_isalnum('z' + 1));
	EXPECT_EQ(0, ft_isalnum('A' - 1));
	EXPECT_EQ(0, ft_isalnum('Z' + 1));
}


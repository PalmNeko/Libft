
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_isdigit, basic_usage) {
	EXPECT_NE(0, ft_isdigit('0'));
	EXPECT_NE(0, ft_isdigit('1'));
	EXPECT_NE(0, ft_isdigit('2'));
	EXPECT_NE(0, ft_isdigit('3'));
	EXPECT_NE(0, ft_isdigit('4'));
	EXPECT_NE(0, ft_isdigit('5'));
	EXPECT_NE(0, ft_isdigit('6'));
	EXPECT_NE(0, ft_isdigit('7'));
	EXPECT_NE(0, ft_isdigit('8'));
	EXPECT_NE(0, ft_isdigit('9'));
	EXPECT_EQ(0, ft_isdigit('0' - 1));
	EXPECT_EQ(0, ft_isdigit('9' + 1));
	EXPECT_EQ(0, ft_isdigit('0' + 255));
	EXPECT_EQ(0, ft_isdigit('9' + 255));
}



#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_isspace, boundary_value) {
	EXPECT_NE(0, ft_isspace(' '));
	EXPECT_NE(0, ft_isspace('\n'));
	EXPECT_NE(0, ft_isspace('\t'));
	EXPECT_NE(0, ft_isspace('\r'));
	EXPECT_NE(0, ft_isspace('\v'));
	EXPECT_NE(0, ft_isspace('\f'));
	EXPECT_NE(0, ft_isspace('\f'));
	EXPECT_EQ(0, ft_isspace(' ' - 1));
	EXPECT_EQ(0, ft_isspace(' ' + 1));
	EXPECT_EQ(0, ft_isspace('\t' - 1));
	EXPECT_EQ(0, ft_isspace('\r' + 1));
}


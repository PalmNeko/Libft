
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_abs, basic_usage) {
	EXPECT_EQ(ft_abs(132974), 132974);
	EXPECT_EQ(ft_abs(-112873), 112873);
}

TEST(ft_abs, boundary_value) {
	EXPECT_EQ(ft_abs(0), 0);
	EXPECT_EQ(ft_abs(1), 1);
	EXPECT_EQ(ft_abs(-1), 1);
	EXPECT_EQ(ft_abs(INT_MIN + 1), INT_MAX);
	EXPECT_EQ(ft_abs(INT_MAX), INT_MAX);
}

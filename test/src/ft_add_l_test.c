
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_add_l, basic_usage) {
	errno = 0;
	EXPECT_EQ(3, ft_add_l(1, 2));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(2, ft_add_l(0, 2));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(2, ft_add_l(2, 0));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(3047, ft_add_l(1024, 2023));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(1025, ft_add_l(1024, 1));
	EXPECT_EQ(0, errno);
}

TEST(ft_add_l, over_flow) {
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_add_l(LONG_MAX, 0));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MAX, ft_add_l(LONG_MAX - 1, 1));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MAX, ft_add_l(LONG_MAX, 1));
	EXPECT_EQ(ERANGE, errno);
}

TEST(ft_add_l, under_flow) {
	errno = 0;
	EXPECT_EQ(LONG_MIN, ft_add_l(LONG_MIN, 0));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MIN, ft_add_l(LONG_MIN + 1, -1));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MIN, ft_add_l(LONG_MIN, -1));
	EXPECT_EQ(ERANGE, errno);
}

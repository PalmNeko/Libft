
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_mul_l, basic_usage) {
	EXPECT_EQ(0, ft_mul_l(0, 0));
	EXPECT_EQ(0, ft_mul_l(30000000, 0));
	EXPECT_EQ(256, ft_mul_l(128, 2));
	EXPECT_EQ((LONG_MAX - 1), ft_mul_l((LONG_MAX - 1) / 2, 2));
	EXPECT_EQ(LONG_MIN, ft_mul_l(LONG_MIN / 2, 2));
}

TEST(ft_mul_l, error_check) {
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_mul_l((LONG_MAX / 2) + 1, 2));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_mul_l(2, (LONG_MAX / 2) + 1));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MIN, ft_mul_l((LONG_MIN / 2) - 1, 2));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MIN, ft_mul_l(2, (LONG_MIN / 2) - 1));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_mul_l(LONG_MIN, -1));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_mul_l(-1, LONG_MIN));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
}

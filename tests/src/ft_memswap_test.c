
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_memswap, basic_usage) {
	int	a;
	int	b;

	a = 12;
	b = 13;
	ft_memswap(&a, &b, sizeof(int));
	EXPECT_EQ(13, a);
	EXPECT_EQ(12, b);
	a = 12;
	b = 12;
	ft_memswap(&a, &b, sizeof(int));
	EXPECT_EQ(12, a);
	EXPECT_EQ(12, b);
}

TEST(ft_memswap, boudary_value) {
	int	a;
	int	b;

	a = INT_MAX;
	b = INT_MIN;
	ft_memswap(&a, &b, sizeof(int));
	EXPECT_EQ(INT_MIN, a);
	EXPECT_EQ(INT_MAX, b);
}

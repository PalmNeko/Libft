
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_memswap, basic_usage) {
	int	a;
	int	b;

	a = 12;
	b = 13;
	EXPECT_EQ(0, ft_memswap(&a, &b, sizeof(int)));
	EXPECT_EQ(13, a);
	EXPECT_EQ(12, b);
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_swap_chr, basic_usage) {
	char	a = 'a';
	char	b = 'b';

	ft_swap_chr(&a, &b);
	EXPECT_EQ('a', b);
	EXPECT_EQ('b', a);
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_xorshift_u32, basic_usage) {
	ASSERT_NE(ft_xorshift_u32(123, 1), ft_xorshift_u32(123, 2));
	ASSERT_EQ(ft_xorshift_u32(123, 1), ft_xorshift_u32(123, 1));
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdbool.h>

TEST(ft_ifl, basic_usage) {
	EXPECT_EQ(0, ft_ifl(true, 0, 123));
	EXPECT_EQ(123, ft_ifl(false, 0, 123));
}

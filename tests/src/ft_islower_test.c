
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_islower, boundary_value) {
	EXPECT_NE(0, ft_islower('a'));
	EXPECT_NE(0, ft_islower('z'));
	EXPECT_EQ(0, ft_islower('a' - 1));
	EXPECT_EQ(0, ft_islower('z' + 1));
	EXPECT_EQ(0, ft_islower('A'));
	EXPECT_EQ(0, ft_islower('Z'));
}


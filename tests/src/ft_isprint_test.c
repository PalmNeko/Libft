
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_isprint, boundary_value) {
	EXPECT_NE(0, ft_isprint(' '));
	EXPECT_NE(0, ft_isprint('~'));
	EXPECT_EQ(0, ft_isprint(' ' - 1));
	EXPECT_EQ(0, ft_isprint('~' + 1));
	EXPECT_EQ(0, ft_isprint(' ' + 255));
	EXPECT_EQ(0, ft_isprint('~' + 255));
}

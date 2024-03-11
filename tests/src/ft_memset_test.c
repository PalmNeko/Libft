
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_memset, basic_usage) {
	char	str[12];

	EXPECT_EQ(str, ft_memset(str, 'A', 12));
	EXPECT_EQ(0, ft_memcmp(str, "AAAAAAAAAAAA", 12));
	EXPECT_EQ(str, ft_memset(str, 'B', 3));
	EXPECT_EQ(0, ft_memcmp(str, "BBBAAAAAAAAA", 12));
	EXPECT_EQ(str, ft_memset(str, 'B', 0));
	EXPECT_EQ(0, ft_memcmp(str, "BBBAAAAAAAAA", 12));
}

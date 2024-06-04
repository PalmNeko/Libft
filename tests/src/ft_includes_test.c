
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_includes, basic_usage) {
	EXPECT_TRUE(ft_includes('a', "ha"));
	EXPECT_TRUE(ft_includes('h', "ha"));
	EXPECT_FALSE(ft_includes('\0', "ha"));
}


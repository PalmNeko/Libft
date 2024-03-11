
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_memcpy, basic_usage) {
	char	buffer[13];
	char	*src = "abcdef";

	EXPECT_EQ(buffer, ft_memcpy(buffer, src, 7));
	EXPECT_STREQ(buffer, src);
	EXPECT_EQ(buffer, ft_memcpy(buffer, src, 0));
	EXPECT_STREQ(buffer, src);
}


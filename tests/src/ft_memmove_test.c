
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_memmove, basic_usage)
{
	char	buffer[13];
	char	*src = "abcdef";

	EXPECT_EQ(buffer, ft_memmove(buffer, src, 7));
	EXPECT_STREQ(buffer, src);
	EXPECT_EQ(buffer, ft_memmove(buffer, src, 0));
	EXPECT_STREQ(buffer, src);
}

TEST(ft_memmove, overlap_memory)
{
	char	buffer[13] = "abcdef";

	EXPECT_EQ(buffer, ft_memmove(buffer, buffer + 1, 2));
	EXPECT_STREQ(buffer, "bccdef");
	EXPECT_EQ(buffer + 1, ft_memmove(buffer + 1, buffer, 2));
	EXPECT_STREQ(buffer, "bbcdef");
}

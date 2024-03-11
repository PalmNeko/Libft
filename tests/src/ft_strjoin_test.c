
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_strjoin, basic_usage) {
	char	*joined;

	joined = ft_strjoin("abc", "def");
	EXPECT_STREQ(joined, "abcdef");
	free(joined);
	joined = ft_strjoin("", "def");
	EXPECT_STREQ(joined, "def");
	free(joined);
	joined = ft_strjoin("abc", "");
	EXPECT_STREQ(joined, "abc");
	free(joined);
	joined = ft_strjoin("", "");
	EXPECT_STREQ(joined, "");
	free(joined);
}

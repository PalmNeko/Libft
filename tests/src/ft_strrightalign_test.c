#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

TEST(ft_strrightalign, basic_usage) {
	char	*line;

	EXPECT_STREQ("  a", line = ft_strrightalign("a", 3));
	free(line);
	EXPECT_STREQ("abc", line = ft_strrightalign("abc", 3));
	free(line);
	EXPECT_STREQ("abcabcabc", line = ft_strrightalign("abcabcabc", 0));
	free(line);
	EXPECT_STREQ("     ", line = ft_strrightalign("", 5));
	free(line);
	EXPECT_STREQ("  abc", line = ft_strrightalign("abc", 5));
	free(line);
}

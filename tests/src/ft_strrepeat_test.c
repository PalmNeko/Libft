#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

TEST(ft_strrepeat, basic_usage) {
	char	*line;

	EXPECT_STREQ("aaa", line = ft_strrepeat("a", 3));
	free(line);
	EXPECT_STREQ("abcabcabc", line = ft_strrepeat("abc", 3));
	free(line);
	EXPECT_STREQ("", line = ft_strrepeat("abcabcabc", 0));
	free(line);
	EXPECT_STREQ("", line = ft_strrepeat("", 12));
	free(line);
}

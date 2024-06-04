#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <errno.h>

TEST(ft_strleftalign, basic_usage) {
	char	*line;

	EXPECT_STREQ("a  ", line = ft_strleftalign("a", 3));
	free(line);
	EXPECT_STREQ("abc", line = ft_strleftalign("abc", 3));
	free(line);
	EXPECT_STREQ("abcabcabc", line = ft_strleftalign("abcabcabc", 0));
	free(line);
	EXPECT_STREQ("     ", line = ft_strleftalign("", 5));
	free(line);
	EXPECT_STREQ("abc  ", line = ft_strleftalign("abc", 5));
	free(line);
}

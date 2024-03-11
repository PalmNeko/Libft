
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_strtrim, basic_usage) {
	char	*trimmed;

	trimmed = ft_strtrim("''abc','def''", "',");
	EXPECT_STREQ("abc','def", trimmed);
	free(trimmed);
	trimmed = ft_strtrim("'abc','def'", "',");
	EXPECT_STREQ("abc','def", trimmed);
	free(trimmed);
	trimmed = ft_strtrim("abc','def", ", '");
	EXPECT_STREQ("abc','def", trimmed);
	free(trimmed);
	trimmed = ft_strtrim("", ", '");
	EXPECT_STREQ("", trimmed);
	trimmed = ft_strtrim(",','", ", '");
	EXPECT_STREQ("", trimmed);
	trimmed = ft_strtrim(",,''", ", '");
	EXPECT_STREQ("", trimmed);
	free(trimmed);
}

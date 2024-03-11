
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_strndup, basic_usage) {
	char	*result;

	result = ft_strndup("abc", 2);
	EXPECT_STREQ("ab", result);
	free(result);
	result = ft_strndup("", 2);
	EXPECT_STREQ("", result);
	free(result);
	result = ft_strndup("ab", 2);
	EXPECT_STREQ("ab", result);
	free(result);
	result = ft_strndup("ab", 0);
	EXPECT_STREQ("", result);
	free(result);
	result = ft_strndup("ab", 1);
	EXPECT_STREQ("a", result);
	free(result);
}

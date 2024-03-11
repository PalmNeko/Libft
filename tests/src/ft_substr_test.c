
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_substr, basic_usage) {
	char	*result;

	result = ft_substr("abcdef", 0, 3);
	EXPECT_STREQ("abc", result);
	free(result);
	result = ft_substr("abcdef", 3, 3);
	EXPECT_STREQ("def", result);
	free(result);
	result = ft_substr("abcdef", 3, 6);
	EXPECT_STREQ("def", result);
	free(result);
	result = ft_substr("abcdef", 3, 0);
	EXPECT_STREQ("", result);
	free(result);
	result = ft_substr("abcdef", 0, 0);
	EXPECT_STREQ("", result);
	free(result);
}

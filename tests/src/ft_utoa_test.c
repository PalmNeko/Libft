
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_utoa, basic_usage) {
	char	*result;

	result = ft_utoa(1239837);
	EXPECT_STREQ("1239837", result);
	free(result);
}

TEST(ft_utoa, boundary_value) {
	char	*result;

	result = ft_utoa(0);
	EXPECT_STREQ("0", result);
	free(result);
	result = ft_utoa(UINT_MAX);
	EXPECT_STREQ("4294967295", result);
	free(result);
	result = ft_utoa(UINT_MAX - 1);
	EXPECT_STREQ("4294967294", result);
	free(result);
}

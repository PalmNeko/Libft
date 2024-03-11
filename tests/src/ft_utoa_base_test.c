
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_utoa_base_str, basic_usage) {
	char	*result;

	result = ft_utoa_base_str(123228129, "0123456789");
	EXPECT_STREQ("123228129", result);
	free(result);
	result = ft_utoa_base_str(123228129, "0123456789ABCDEF");
	EXPECT_STREQ("7584FE1", result);
	free(result);
}

TEST(ft_utoa_base_str, boundary_value) {
	char	*result;

	result = ft_utoa_base_str(0, "0123456789");
	EXPECT_STREQ("0", result);
	free(result);
	result = ft_utoa_base_str(UINT_MAX, "0123456789");
	EXPECT_STREQ("4294967295", result);
	free(result);
	result = ft_utoa_base_str(UINT_MAX - 1, "0123456789");
	EXPECT_STREQ("4294967294", result);
	free(result);
	result = ft_utoa_base_str(UINT_MAX, "0123456789ABCDEF");
	EXPECT_STREQ("FFFFFFFF", result);
	free(result);
	result = ft_utoa_base_str(UINT_MAX, "01");
	EXPECT_STREQ("11111111111111111111111111111111", result);
	free(result);
	result = ft_utoa_base_str(UINT_MAX, "ab");
	EXPECT_STREQ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", result);
	free(result);
}

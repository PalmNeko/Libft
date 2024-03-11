
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_ultoa_base_str, basic_usage) {
	char	*result;

	result = ft_ultoa_base_str(123228129837, "0123456789");
	EXPECT_STREQ("123228129837", result);
	free(result);
	result = ft_ultoa_base_str(123228129837, "0123456789ABCDEF");
	EXPECT_STREQ("1CB0F80A2D", result);
	free(result);
}

#if ULONG_MAX == 9223372036854775807L *2UL+1UL

TEST(ft_ultoa_base_str, boundary_value) {
	char	*result;

	result = ft_ultoa_base_str(0, "0123456789");
	EXPECT_STREQ("0", result);
	free(result);
	result = ft_ultoa_base_str(ULONG_MAX, "0123456789");
	EXPECT_STREQ("18446744073709551615", result);
	free(result);
	result = ft_ultoa_base_str(ULONG_MAX - 1, "0123456789");
	EXPECT_STREQ("18446744073709551614", result);
	free(result);
	result = ft_ultoa_base_str(ULONG_MAX, "0123456789ABCDEF");
	EXPECT_STREQ("FFFFFFFFFFFFFFFF", result);
	free(result);
	result = ft_ultoa_base_str(ULONG_MAX, "01");
	EXPECT_STREQ("1111111111111111111111111111111111111111111111111111111111111111", result);
	free(result);
	result = ft_ultoa_base_str(ULONG_MAX, "ab");
	EXPECT_STREQ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", result);
	free(result);
}

#else

#endif

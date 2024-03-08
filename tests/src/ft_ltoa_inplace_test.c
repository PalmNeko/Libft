
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_ltoa_inplace, basic) {
	char	buffer[23];
	EXPECT_STREQ("6112276220", ft_ltoa_inplace(824802448, buffer, 8));
	EXPECT_STREQ("10644243160", ft_ltoa_inplace(1183925872, buffer, 8));
	EXPECT_STREQ("592155184", ft_ltoa_inplace(592155184, buffer, 10));
	EXPECT_STREQ("727806197", ft_ltoa_inplace(727806197, buffer, 10));
	EXPECT_STREQ("2dbd5f9a", ft_ltoa_inplace(767385498, buffer, 16));
	EXPECT_STREQ("488cd92a", ft_ltoa_inplace(1217190186, buffer, 16));
	EXPECT_STREQ("-6112276220", ft_ltoa_inplace(-824802448, buffer, 8));
	EXPECT_STREQ("-10644243160", ft_ltoa_inplace(-1183925872, buffer, 8));
	EXPECT_STREQ("-592155184", ft_ltoa_inplace(-592155184, buffer, 10));
	EXPECT_STREQ("-727806197", ft_ltoa_inplace(-727806197, buffer, 10));
	EXPECT_STREQ("-2dbd5f9a", ft_ltoa_inplace(-767385498, buffer, 16));
	EXPECT_STREQ("-488cd92a", ft_ltoa_inplace(-1217190186, buffer, 16));
}

TEST(ft_ltoa_inplace, boundary_value) {
	char	buffer[23];
	EXPECT_STREQ("0", ft_ltoa_inplace(0, buffer, 8));
	EXPECT_STREQ("0", ft_ltoa_inplace(0, buffer, 10));
	EXPECT_STREQ("0", ft_ltoa_inplace(0, buffer, 16));
	EXPECT_STREQ("1", ft_ltoa_inplace(1, buffer, 8));
	EXPECT_STREQ("1", ft_ltoa_inplace(1, buffer, 10));
	EXPECT_STREQ("1", ft_ltoa_inplace(1, buffer, 16));
	EXPECT_STREQ("-1", ft_ltoa_inplace(-1, buffer, 8));
	EXPECT_STREQ("-1", ft_ltoa_inplace(-1, buffer, 10));
	EXPECT_STREQ("-1", ft_ltoa_inplace(-1, buffer, 16));
	if (LONG_MAX == 9223372036854775807)
	{
		EXPECT_STREQ("777777777777777777776", ft_ltoa_inplace(LONG_MAX - 1, buffer, 8));
		EXPECT_STREQ("9223372036854775806", ft_ltoa_inplace(LONG_MAX - 1, buffer, 10));
		EXPECT_STREQ("7ffffffffffffffe", ft_ltoa_inplace(LONG_MAX - 1, buffer, 16));
		EXPECT_STREQ("-777777777777777777777", ft_ltoa_inplace(LONG_MIN + 1, buffer, 8));
		EXPECT_STREQ("-9223372036854775807", ft_ltoa_inplace(LONG_MIN + 1, buffer, 10));
		EXPECT_STREQ("-7fffffffffffffff", ft_ltoa_inplace(LONG_MIN + 1, buffer, 16));
		EXPECT_STREQ("777777777777777777777", ft_ltoa_inplace(LONG_MAX, buffer, 8));
		EXPECT_STREQ("9223372036854775807", ft_ltoa_inplace(LONG_MAX, buffer, 10));
		EXPECT_STREQ("7fffffffffffffff", ft_ltoa_inplace(LONG_MAX, buffer, 16));
		EXPECT_STREQ("-1000000000000000000000", ft_ltoa_inplace(LONG_MIN, buffer, 8));
		EXPECT_STREQ("-9223372036854775808", ft_ltoa_inplace(LONG_MIN, buffer, 10));
		EXPECT_STREQ("-8000000000000000", ft_ltoa_inplace(LONG_MIN, buffer, 16));
	}
	else
	{
		EXPECT_STREQ("17777777776", ft_ltoa_inplace(LONG_MAX - 1, buffer, 8));
		EXPECT_STREQ("2147483646", ft_ltoa_inplace(LONG_MAX - 1, buffer, 10));
		EXPECT_STREQ("7ffffffe", ft_ltoa_inplace(LONG_MAX - 1, buffer, 16));
		EXPECT_STREQ("-17777777777", ft_ltoa_inplace(LONG_MIN + 1, buffer, 8));
		EXPECT_STREQ("-2147483647", ft_ltoa_inplace(LONG_MIN + 1, buffer, 10));
		EXPECT_STREQ("-7fffffff", ft_ltoa_inplace(LONG_MIN + 1, buffer, 16));
		EXPECT_STREQ("17777777777", ft_ltoa_inplace(LONG_MAX, buffer, 8));
		EXPECT_STREQ("2147483647", ft_ltoa_inplace(LONG_MAX, buffer, 10));
		EXPECT_STREQ("7fffffff", ft_ltoa_inplace(LONG_MAX, buffer, 16));
		EXPECT_STREQ("-20000000000", ft_ltoa_inplace(LONG_MIN, buffer, 8));
		EXPECT_STREQ("-2147483648", ft_ltoa_inplace(LONG_MIN, buffer, 10));
		EXPECT_STREQ("-80000000", ft_ltoa_inplace(LONG_MIN, buffer, 16));
	}
}

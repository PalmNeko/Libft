
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_itoa, basic_usage) {
	char	*result;

	result = ft_itoa(123); EXPECT_STREQ("123", result); free(result);
	result = ft_itoa(321); EXPECT_STREQ("321", result); free(result);
	result = ft_itoa(-12379); EXPECT_STREQ("-12379", result); free(result);
	result = ft_itoa(-231); EXPECT_STREQ("-231", result); free(result);
	result = ft_itoa(-231); EXPECT_STREQ("-231", result); free(result);
}

TEST(ft_itoa, boudary_value)
{
	char	*result;

	result = ft_itoa(0); EXPECT_STREQ("0", result); free(result);
	result = ft_itoa(1); EXPECT_STREQ("1", result); free(result);
	result = ft_itoa(-1); EXPECT_STREQ("-1", result); free(result);
	result = ft_itoa(INT_MAX); EXPECT_STREQ("2147483647", result); free(result);
	result = ft_itoa(INT_MIN); EXPECT_STREQ("-2147483648", result); free(result);
	result = ft_itoa(INT_MAX - 1); EXPECT_STREQ("2147483646", result); free(result);
	result = ft_itoa(INT_MIN + 1); EXPECT_STREQ("-2147483647", result); free(result);
}

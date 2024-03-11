
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strrev, basic_usage) {
	char	str[] = "abcdef";

	ft_strrev(str);
	EXPECT_STREQ("fedcba", str);
	ft_strrev(str);
	EXPECT_STREQ("abcdef", str);
	str[0] = '\0';
	ft_strrev(str);
	EXPECT_STREQ("", str);
}


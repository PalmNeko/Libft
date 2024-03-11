
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_strdup, basic_usage) {
	char	*dupped;
	char	*src;

	src = "abcdef";
	dupped = ft_strdup(src);
	ASSERT_NE(0, src != dupped);
	EXPECT_STREQ(src, dupped);
	free(dupped);
	src = "";
	dupped = ft_strdup(src);
	ASSERT_NE(0, src != dupped);
	EXPECT_STREQ(src, dupped);
	free(dupped);
}



#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_calloc, basic_usage) {
	char *str;
	char cmp[10];

	str = (char *)ft_calloc(10, sizeof(char));
	if (str == NULL)
		return ;
	ft_bzero(cmp, 10);
	EXPECT_EQ(0, ft_memcmp(str, cmp, 10));
	free(str);
}

TEST(ft_calloc, error_check) {
	int *ary;

	ary = (int *)ft_calloc(SIZE_MAX, 2);
	EXPECT_EQ((int *)0, ary);
	EXPECT_EQ(ENOMEM, errno);
}

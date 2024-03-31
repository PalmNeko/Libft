
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	cmp_int(const void *left, const void *right);

TEST(ft_bsearch, basic_usage)
{
	int		*sorted_value;
	t_bsearch_arg	bsearch_arg;

	sorted_value = (int []){1, 2, 3, 4};
	bsearch_arg = (t_bsearch_arg){.base = sorted_value, .size = 4,
		.compar = cmp_int, .nmemb = 4};
	bsearch_arg.key = &sorted_value[0];
	EXPECT_EQ(&sorted_value[0], ft_bsearch(&bsearch_arg));
	bsearch_arg.key = &sorted_value[1];
	EXPECT_EQ(&sorted_value[1], ft_bsearch(&bsearch_arg));
	bsearch_arg.key = &sorted_value[2];
	EXPECT_EQ(&sorted_value[2], ft_bsearch(&bsearch_arg));
	bsearch_arg.key = &sorted_value[3];
	EXPECT_EQ(&sorted_value[3], ft_bsearch(&bsearch_arg));
	bsearch_arg.key = (int []){1};
	EXPECT_EQ(&sorted_value[0], ft_bsearch(&bsearch_arg));
	bsearch_arg.key = (int []){4};
	EXPECT_EQ(&sorted_value[3], ft_bsearch(&bsearch_arg));
	bsearch_arg.key = (int []){5};
	EXPECT_EQ(NULL, ft_bsearch(&bsearch_arg));
	bsearch_arg.key = (int []){0};
	EXPECT_EQ(NULL, ft_bsearch(&bsearch_arg));
}

static int	cmp_int(const void *left, const void *right)
{
	if (*(int *)left < *(int *)right)
		return (-1);
	else if (*(int *)left > *(int *)right)
		return (1);
	else
		return (0);
}

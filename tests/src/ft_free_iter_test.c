
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

static int free_cnt = 0;
void	wrap_free(void *ptr)
{
	free(ptr);
	free_cnt += 1;
}

TEST(ft_free_iter, basic_usage) {
	t_free_args frees[3];
	char		*tmp;

	tmp = (char *)malloc(123);
	frees[0].free_func = wrap_free;
	frees[0].arg = tmp;
	tmp = (char *)malloc(123);
	frees[1].free_func = wrap_free;
	frees[1].arg = tmp;
	tmp = (char *)malloc(123);
	frees[2].free_func = wrap_free;
	frees[2].arg = tmp;
	ft_free_iter(frees, 3);
	EXPECT_EQ(3, free_cnt);
}


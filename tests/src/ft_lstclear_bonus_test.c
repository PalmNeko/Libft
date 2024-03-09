
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	g_del_cnt;

static void	_del_one_function(void *content)
{
	*(int *)content = 2;
	g_del_cnt += 1;
}

TEST(ft_lstclear, basic_usage) {
	t_list	*root = NULL;
	int		buf[3];

	buf[0] = 1;
	buf[1] = 1;
	buf[2] = 1;
	ft_lstadd_front(&root, ft_lstnew(&buf[0]));
	ft_lstadd_front(&root, ft_lstnew(&buf[1]));
	ft_lstadd_front(&root, ft_lstnew(&buf[2]));
	g_del_cnt = 0;
	ft_lstclear(&root, _del_one_function);
	EXPECT_EQ(NULL, root);
	EXPECT_EQ(3, g_del_cnt);
	EXPECT_EQ(2, buf[0]);
	EXPECT_EQ(2, buf[1]);
	EXPECT_EQ(2, buf[2]);
}


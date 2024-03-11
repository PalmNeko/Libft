
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	g_called_cnt;
static void	*_squre(void *value)
{
	static int	values[3];
	static int	cnt;

	values[cnt] = (*(int *)value) * (*(int *)value);
	cnt++;
	g_called_cnt++;

	return (&values[cnt - 1]);
}


static void	_del_func(void *content)
{
	(void)content;
}

TEST(ft_lstmap_bonus, basic_usage)
{
	t_list	*root;
	t_list	*squared_root;

	root = (t_list []) {{
		.content = (int []){1},
		.next = (t_list []) {{
			.content = (int []){3},
			.next = NULL
		}}
	}};
	squared_root = ft_lstmap(root, _squre, _del_func);
	EXPECT_EQ(2, g_called_cnt);
	EXPECT_EQ(1, *(int *)squared_root->content);
	EXPECT_EQ(9, *(int *)squared_root->next->content);
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	g_called_cnt;
static void	*_squre(void *value)
{
	static int	values[3];

	values[g_called_cnt] = (*(int *)value) * (*(int *)value);
	g_called_cnt++;
	return (&values[g_called_cnt - 1]);
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
	ft_lstclear(&squared_root, _del_func);
}

TEST(ft_lstmap_bonus, two_way_list)
{
	t_list	*root;
	t_list	*squared_root;

	root = NULL;
	ft_lstadd_back(&root, ft_lstnew((int []){1}));
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	g_called_cnt = 0;
	squared_root = ft_lstmap(root, _squre, _del_func);
	EXPECT_EQ(2, g_called_cnt);
	EXPECT_EQ(1, *(int *)squared_root->content);
	EXPECT_EQ(1, *(int *)squared_root->next->prev->content);
	EXPECT_EQ(9, *(int *)squared_root->next->content);
	EXPECT_EQ(NULL, squared_root->next->next);
	EXPECT_EQ(NULL, squared_root->prev);
	ft_lstclear(&squared_root, _del_func);
	ft_lstclear(&root, _del_func);
}

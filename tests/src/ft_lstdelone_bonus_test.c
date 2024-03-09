
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	g_del_cnt;

static void	_delone_(void *content)
{
	*(int *)content = 4;
	g_del_cnt += 1;
}

TEST(ft_lstdelone_bonus, basic_usage) {
	t_list	*root;
	t_list	*tmp;
	int		values[3] = {1, 2, 3};

	root = NULL;
	ft_lstadd_front(&root, ft_lstnew(&values[0]));
	ft_lstadd_front(&root, ft_lstnew(&values[1]));
	ft_lstadd_front(&root, ft_lstnew(&values[2]));
	tmp = root;
	root = root->next;
	ft_lstdelone(tmp, _delone_);
	tmp = root;
	root = root->next;
	ft_lstdelone(tmp, _delone_);
	tmp = root;
	root = root->next;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(3, g_del_cnt);
	EXPECT_EQ(NULL, root);
	EXPECT_EQ(4, values[0]);
	EXPECT_EQ(4, values[1]);
	EXPECT_EQ(4, values[2]);
}

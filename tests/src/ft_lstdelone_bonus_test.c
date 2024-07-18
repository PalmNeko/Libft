
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

	g_del_cnt = 0;
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

TEST(ft_lstdelone_bonus, two_way_list) {
	t_list	*root;
	t_list	*tmp;
	int		values[3] = {1, 2, 3};

	g_del_cnt = 0;
	root = NULL;
	ft_lstadd_front(&root, ft_lstnew(&values[0]));
	ft_lstadd_front(&root, ft_lstnew(&values[1]));
	ft_lstadd_front(&root, ft_lstnew(&values[2]));
	tmp = root->next;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(1, *(int *)root->next->content);
	EXPECT_EQ(3, *(int *)root->next->prev->content);
	tmp = root;
	root = root->next;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(1, *(int *)root->content);
	EXPECT_EQ(NULL, root->prev);
	EXPECT_EQ(NULL, root->next);
	tmp = root;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(3, g_del_cnt);
	EXPECT_EQ(4, values[0]);
	EXPECT_EQ(4, values[1]);
	EXPECT_EQ(4, values[2]);
}

TEST(ft_lstdelone_bonus, circular_list) {
	t_list	*root;
	t_list	*tmp;
	int		values[3] = {1, 2, 3};

	g_del_cnt = 0;
	root = NULL;
	ft_lstadd_back(&root, ft_lstnewcircular(&values[0]));
	ft_lstadd_back(&root, ft_lstnewcircular(&values[1]));
	ft_lstadd_back(&root, ft_lstnewcircular(&values[2]));
	tmp = root;
	root = root->next;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(2, *(int *)root->prev->prev->content);
	EXPECT_EQ(2, *(int *)root->next->next->content);
	EXPECT_EQ(3, *(int *)root->next->content);
	EXPECT_EQ(3, *(int *)root->prev->content);
	tmp = root;
	root = root->next;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(3, *(int *)root->content);
	EXPECT_EQ(root, root->prev);
	EXPECT_EQ(root, root->next);
	tmp = root;
	ft_lstdelone(tmp, _delone_);
	EXPECT_EQ(3, g_del_cnt);
	EXPECT_EQ(4, values[0]);
	EXPECT_EQ(4, values[1]);
	EXPECT_EQ(4, values[2]);
}

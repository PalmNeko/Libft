
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstadd_front_bonus, basic_usage) {
	t_list	*root;

	root = (t_list[]){{.content=(int []){1}, .next = NULL, .prev = NULL}};
	ft_lstadd_front(&root, (t_list[]){{.content=(int []){2}, .next = NULL, .prev = NULL}});
	EXPECT_EQ(2, *(int *)root->content);
	ft_lstadd_front(&root, (t_list[]){{.content=(int []){3}, .next = NULL, .prev = NULL}});
	EXPECT_EQ(3, *(int *)root->content);
	EXPECT_EQ(2, *(int *)root->next->content);
	EXPECT_EQ(1, *(int *)root->next->next->content);
	root = NULL;
	ft_lstadd_front(&root, (t_list[]){{.content=(int []){1}, .next = NULL, .prev = NULL}});
	EXPECT_EQ(1, *(int *)root->content);
}

TEST(ft_lstadd_front_bonus, two_way_list) {
	t_list	*root;
	t_list	*tmp;

	root = ft_lstnew((int []){1});
	ft_lstadd_front(&root, ft_lstnew((int []){2}));
	EXPECT_EQ(NULL, root->prev);
	EXPECT_EQ(2, *(int *)root->content);
	EXPECT_EQ(1, *(int *)root->next->content);
	EXPECT_EQ(root, root->next->prev);
	tmp = root;
	root = root->next;
	ft_lstadd_front(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(3, *(int *)tmp->prev->content);
	EXPECT_EQ(2, *(int *)tmp->prev->next->content);
	EXPECT_EQ(1, *(int *)tmp->prev->next->next->content);
	EXPECT_EQ(3, *(int *)root->prev->prev->content);
	EXPECT_EQ(2, *(int *)root->prev->content);
	EXPECT_EQ(1, *(int *)root->content);
	EXPECT_EQ(NULL, root->next);
	ft_lstclear(&root, (void (*)())ft_voidnop);
}

TEST(ft_lstadd_front_bonus, circular_list) {
	t_list	*root;

	root = ft_lstnewcircular((int []){1});
	ft_lstadd_front(&root, ft_lstnewcircular((int []){2}));
	EXPECT_EQ(2, *(int *)root->content);
	EXPECT_EQ(1, *(int *)root->next->content);
	EXPECT_EQ(2, *(int *)root->next->next->content);
	EXPECT_EQ(1, *(int *)root->prev->content);
	EXPECT_EQ(2, *(int *)root->prev->prev->content);
	EXPECT_EQ(root, root->prev->prev);
	root = root->next;
	ft_lstadd_front(&root, ft_lstnewcircular((int []){3}));
	EXPECT_EQ(3, *(int *)root->content);
	EXPECT_EQ(2, *(int *)root->prev->content);
	EXPECT_EQ(1, *(int *)root->prev->prev->content);
	EXPECT_EQ(3, *(int *)root->prev->prev->prev->content);
	EXPECT_EQ(1, *(int *)root->next->content);
	EXPECT_EQ(2, *(int *)root->next->next->content);
	EXPECT_EQ(3, *(int *)root->next->next->next->content);
	ft_lstclear(&root, (void (*)())ft_voidnop);
}

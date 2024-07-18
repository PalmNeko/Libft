
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstadd_back_bonus, basic_usage) {
	t_list	*root;

	root = (t_list[]){{.content=(int []){1}, .next = NULL}};
	ft_lstadd_back(&root, (t_list[]){{.content=(int []){2}, .next = NULL}});
	EXPECT_EQ(2, *(int *)root->next->content);
	ft_lstadd_back(&root, (t_list[]){{.content=(int []){3}, .next = NULL}});
	EXPECT_EQ(3, *(int *)root->next->next->content);
	EXPECT_EQ(NULL, root->next->next->next);
	root = NULL;
	ft_lstadd_back(&root, (t_list[]){{.content=(int []){1}, .next = NULL}});
	EXPECT_EQ(1, *(int *)root->content);
}

TEST(ft_lstadd_back_bonus, two_way_list) {
	t_list	*root;

	root = ft_lstnew((int []){1});
	ft_lstadd_back(&root, ft_lstnew((int []){2}));
	EXPECT_EQ(2, *(int *)root->next->content);
	EXPECT_EQ(1, *(int *)root->next->prev->content);
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(3, *(int *)root->next->next->content);
	EXPECT_EQ(1, *(int *)root->next->next->prev->prev->content);
	EXPECT_EQ(NULL, root->next->next->next);
	ft_lstclear(&root, (void (*)(void *))ft_voidnop);
	root = NULL;
	ft_lstadd_back(&root, ft_lstnew((int []){1}));
	EXPECT_EQ(1, *(int *)root->content);
	EXPECT_EQ(NULL, root->next);
	EXPECT_EQ(NULL, root->prev);
	ft_lstadd_back(&root, ft_lstnew((int []){2}));
	root = root->next;
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(2, *(int *)root->content);
	EXPECT_EQ(3, *(int *)root->next->content);
	EXPECT_EQ(NULL, root->next->next);
	EXPECT_EQ(1, *(int *)root->prev->content);
	EXPECT_EQ(NULL, root->prev->prev);
	root = root->prev;
	ft_lstclear(&root, (void (*)(void *))ft_voidnop);
}

TEST(ft_lstadd_back_bonus, circular_list) {
	t_list	*root;

	root = ft_lstnewcircular((int []){1});
	ft_lstadd_back(&root, ft_lstnew((int []){2}));
	EXPECT_EQ(2, *(int *)root->next->content);
	EXPECT_EQ(1, *(int *)root->next->next->content);
	EXPECT_EQ(1, *(int *)root->next->prev->content);
	EXPECT_EQ(2, *(int *)root->prev->content);
	EXPECT_EQ(1, *(int *)root->prev->prev->content);
	EXPECT_EQ(1, *(int *)root->prev->next->content);
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(2, *(int *)root->next->content);
	EXPECT_EQ(3, *(int *)root->next->next->content);
	EXPECT_EQ(1, *(int *)root->next->next->next->content);
	EXPECT_EQ(3, *(int *)root->prev->content);
	EXPECT_EQ(2, *(int *)root->prev->prev->content);
	EXPECT_EQ(1, *(int *)root->prev->prev->prev->content);
	root = root->next;
	ft_lstadd_back(&root, ft_lstnew((int []){4}));
	EXPECT_EQ(3, *(int *)root->next->content);
	EXPECT_EQ(1, *(int *)root->next->next->content);
	EXPECT_EQ(4, *(int *)root->next->next->next->content);
	EXPECT_EQ(2, *(int *)root->next->next->next->next->content);
	EXPECT_EQ(4, *(int *)root->prev->content);
	EXPECT_EQ(1, *(int *)root->prev->prev->content);
	EXPECT_EQ(3, *(int *)root->prev->prev->prev->content);
	EXPECT_EQ(2, *(int *)root->prev->prev->prev->prev->content);
	ft_lstclear(&root, (void (*)(void *))ft_voidnop);
}

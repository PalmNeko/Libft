
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstfirst, basic_usage) {
	t_list	*root;

	root = (t_list []) {{
		.content = (int []){1},
		.next = (t_list	[]) {{
			.content = (int []){2},
			.next = NULL,
		}}
	}};
	EXPECT_EQ(1, *(int *)ft_lstfirst(root)->content);
	EXPECT_NE(NULL, ft_lstfirst(root)->next);
	EXPECT_EQ(NULL, ft_lstfirst(NULL));
}

TEST(ft_lstfirst, two_way_list) {
	t_list	*root;

	root = NULL;
	ft_lstadd_back(&root, ft_lstnew((int []){1}));
	ft_lstadd_back(&root, ft_lstnew((int []){2}));
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(1, *(int *)ft_lstfirst(root)->content);
	EXPECT_EQ(1, *(int *)ft_lstfirst(root->next)->content);
	EXPECT_EQ(1, *(int *)ft_lstfirst(root->next->next)->content);
	EXPECT_EQ(NULL, ft_lstfirst(root)->prev);
	EXPECT_EQ(NULL, ft_lstfirst(NULL));
	ft_lstclear(&root, (void(*)())ft_voidnop);
}

TEST(ft_lstfirst, circular_list) {
	t_list	*root;

	root = NULL;
	ft_lstadd_back(&root, ft_lstnewcircular((int []){1}));
	ft_lstadd_back(&root, ft_lstnew((int []){2}));
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(1, *(int *)ft_lstfirst(root)->content);
	EXPECT_EQ(2, *(int *)ft_lstfirst(root->next)->content);
	EXPECT_EQ(3, *(int *)ft_lstfirst(root->next->next)->content);
	EXPECT_EQ(3, *(int *)ft_lstfirst(root->prev)->content);
	EXPECT_EQ(NULL, ft_lstfirst(NULL));
	ft_lstclear(&root, (void(*)())ft_voidnop);
}

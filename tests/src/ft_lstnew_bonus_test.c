
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstnew_bonus, basic_usage) {
	t_list	*root;

	root = ft_lstnew((int []){1});
	ASSERT_NE(NULL, root);
	EXPECT_EQ(1, *(int *)root->content);
	ft_lstdelone(root, (void(*)(void *))ft_voidnop);
}

TEST(ft_lstnew_bonus, two_way_list) {
	t_list	*root;

	root = ft_lstnew((int []){1});
	ASSERT_NE(NULL, root);
	EXPECT_EQ(1, *(int *)root->content);
	EXPECT_EQ(NULL, root->next);
	EXPECT_EQ(NULL, root->prev);
	ft_lstdelone(root, (void(*)(void *))ft_voidnop);
}

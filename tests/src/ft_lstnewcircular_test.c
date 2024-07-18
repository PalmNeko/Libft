
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstnewcircular, circular_list) {
	t_list	*root;

	root = ft_lstnewcircular((int []){1});
	ASSERT_NE(NULL, root);
	EXPECT_EQ(1, *(int *)root->content);
	EXPECT_EQ(root, root->next);
	EXPECT_EQ(root, root->prev);
	ft_lstdelone(root, (void(*)(void *))ft_voidnop);
}

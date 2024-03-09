
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

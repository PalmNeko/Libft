
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstlast_bonus, basic_usage) {
	t_list	*root;

	root = (t_list []) {{
		.content = (int []){1},
		.next = (t_list	[]) {{
			.content = (int []){2},
			.next = NULL,
		}}
	}};
	EXPECT_EQ(2, *(int *)ft_lstlast(root)->content);
	EXPECT_EQ(NULL, ft_lstlast(root)->next);
	EXPECT_EQ(NULL, ft_lstlast(NULL));
}

TEST(ft_lstlast_bonus, two_way_list) {
	t_list	*root;

	root = NULL;
	ft_lstadd_back(&root, ft_lstnew((int []){1}));
	ft_lstadd_back(&root, ft_lstnew((int []){2}));
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	EXPECT_EQ(3, *(int *)ft_lstlast(root)->content);
	EXPECT_EQ(3, *(int *)ft_lstlast(root->next)->content);
	EXPECT_EQ(3, *(int *)ft_lstlast(root->next->next)->content);
	EXPECT_EQ(NULL, ft_lstlast(root)->next);
	EXPECT_EQ(NULL, ft_lstlast(NULL));
	ft_lstclear(&root, (void(*)())ft_voidnop);
}

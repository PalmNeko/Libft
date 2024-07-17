
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_lstsize_bonus, basic_usage) {
	t_list	*root = NULL;

	EXPECT_EQ(0, ft_lstsize(root));
	root = (t_list []) {{
		.content = NULL,
		.next = (t_list[]) {{
			.content = NULL,
			.next = NULL
		}}
	}};
	EXPECT_EQ(2, ft_lstsize(root));
}

TEST(ft_lstsize_bonus, two_way_list) {
	t_list	*root = NULL;

	EXPECT_EQ(0, ft_lstsize(root));
	ft_lstadd_back(&root, ft_lstnew((int []){3}));
	ft_lstadd_front(&root, ft_lstnew((int []){2}));
	ft_lstadd_front(&root, ft_lstnew((int []){1}));
	EXPECT_EQ(3, ft_lstsize(root));
	EXPECT_EQ(3, ft_lstsize(root->next));
	ft_lstclear(&root, (void (*)())ft_voidnop);
}

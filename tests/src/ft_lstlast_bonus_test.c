
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



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

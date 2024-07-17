
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	g_value = 0;
static void	count_up(void *content)
{
	if (content == NULL)
		g_value = 0;
	else
	{
		g_value += *(int *)content;
	}
	return ;
}

TEST(ft_lstiter, basic_usage) {
	t_list	*root;

	root = NULL;
	count_up(NULL);
	ft_lstiter(root, count_up);
	EXPECT_EQ(0, g_value);
	root = (t_list []) {{
		.content = (int []){1},
		.next = (t_list	[]) {{
			.content = (int []){2},
			.next = NULL,
		}}
	}};
	ft_lstiter(root, count_up);
	EXPECT_EQ(3, g_value);
}

TEST(ft_lstiter, two_way_list) {
	t_list	*root;

	root = NULL;
	count_up(NULL);
	ft_lstiter(root, count_up);
	EXPECT_EQ(0, g_value);
	root = (t_list []) {{
		.content = (int []){1},
		.next = (t_list	[]) {{
			.content = (int []){2},
			.next = NULL,
		}}
	}};
	ft_lstiter(root, count_up);
	EXPECT_EQ(3, g_value);
}

TEST(ft_lstiter, circular_list) {
	t_list	*root;

	root = NULL;
	count_up(NULL);
	ft_lstiter(root, count_up);
	EXPECT_EQ(0, g_value);
	root = (t_list []) {{
		.content = (int []){1},
		.next = NULL,
	}};
	ft_lstadd_front(&root, (t_list []) {{
		.content = (int []){2},
		.next = NULL,
		.prev = NULL,
	}});
	ft_lstiter(root, count_up);
	EXPECT_EQ(3, g_value);
}

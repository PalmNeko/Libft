
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_lst_to_array, basic_usage)
{
	t_list	*lst;
	int		**values;
	size_t	size;

	lst = ft_array_to_lst((void *[]){
		(int []){1},
		(int []){2},
		(int []){3},
	}, 3);
	ASSERT_NE(lst, NULL);
	values = (int **)ft_lst_to_array(lst, &size);
	ASSERT_NE(values, NULL);
	EXPECT_TRUE(size == 3);
	EXPECT_EQ(*values[0], 1);
	EXPECT_EQ(*values[1], 2);
	EXPECT_EQ(*values[2], 3);
	free(values);
	ft_lstclear(&lst, (void(*)(void *))ft_voidnop);
}

TEST(ft_lst_to_array, two_way_list)
{
	t_list	*lst;
	int		**values;
	size_t	size;

	lst = ft_array_to_lst((void *[]){
		(int []){1},
		(int []){2},
		(int []){3},
	}, 3);
	ASSERT_NE(lst, NULL);
	values = (int **)ft_lst_to_array(lst, &size);
	ASSERT_NE(values, NULL);
	EXPECT_TRUE(size == 3);
	EXPECT_EQ(*values[0], 1);
	EXPECT_EQ(*values[1], 2);
	EXPECT_EQ(*values[2], 3);
	free(values);
	ft_lstclear(&lst, (void(*)(void *))ft_voidnop);
}

TEST(ft_lst_to_array, circular_list)
{
	t_list	*lst;
	int		**values;
	size_t	size;

	lst = ft_lstnewcircular((int []){1});
	ft_lstadd_back(&lst, ft_lstnew((int []){2}));
	ft_lstadd_back(&lst, ft_lstnew((int []){3}));
	values = (int **)ft_lst_to_array(lst, &size);
	ASSERT_NE(values, NULL);
	EXPECT_TRUE(size == 3);
	EXPECT_EQ(*values[0], 1);
	EXPECT_EQ(*values[1], 2);
	EXPECT_EQ(*values[2], 3);
	free(values);
	ft_lstclear(&lst, (void(*)(void *))ft_voidnop);
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_array_to_lst, basic_usage) {
	t_list	*lst;

	lst = ft_array_to_lst((void *[]){
		(int []){1},
		(int []){2},
		(int []){3},
	}, 3);
	ASSERT_NE(NULL, lst);
	EXPECT_EQ(ft_lstsize(lst), 3);
	EXPECT_EQ(*(int *)lst->content, 1);
	EXPECT_EQ(*(int *)lst->next->content, 2);
	EXPECT_EQ(*(int *)lst->next->next->content, 3);
	ft_lstclear(&lst, (void (*)())ft_voidnop);
}

TEST(ft_array_to_lst, two_way) {
	t_list	*lst;

	lst = ft_array_to_lst((void *[]){
		(int []){1},
		(int []){2},
		(int []){3},
	}, 3);
	ASSERT_NE(NULL, lst);
	EXPECT_EQ(ft_lstsize(lst), 3);
	EXPECT_EQ(*(int *)lst->content, 1);
	EXPECT_EQ(*(int *)lst->next->prev->content, 1);
	EXPECT_EQ(*(int *)lst->next->next->prev->prev->content, 1);
	ft_lstclear(&lst, (void (*)())ft_voidnop);
}

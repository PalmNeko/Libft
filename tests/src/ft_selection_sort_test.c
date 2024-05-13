
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	cmp_value(const void *value1, const void *value2){
	return (*(int *)value1 - *(int *)value2);
}

TEST(ft_selection_sort, basic_usage) {
	int	*values;

	values = (int []){5, 3, 1, 6, 8, 9, 4, 2, 4, 9};
	ft_selection_sort(values, 10, sizeof(int), cmp_value);
	EXPECT_EQ(1, values[0]);
	EXPECT_EQ(2, values[1]);
	EXPECT_EQ(3, values[2]);
	EXPECT_EQ(4, values[3]);
	EXPECT_EQ(4, values[4]);
	EXPECT_EQ(5, values[5]);
	EXPECT_EQ(6, values[6]);
	EXPECT_EQ(8, values[7]);
	EXPECT_EQ(9, values[8]);
	EXPECT_EQ(9, values[9]);
}

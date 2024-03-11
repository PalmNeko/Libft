
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_memcmp, basic_usage) {
	EXPECT_EQ(0, ft_memcmp("abc", "abc", 3));
	EXPECT_EQ(0, ft_memcmp("tokyo tower", "tokyo tower", 8));
	EXPECT_EQ(0, ft_memcmp("tokyo skytree", "tokyo tower", 5));
	EXPECT_GT(0, ft_memcmp("tokyo skytree", "tokyo tower", 7));
	EXPECT_LT(0, ft_memcmp("tokyo tower", "tokyo skytree", 7));
	EXPECT_EQ(0, ft_memcmp("tokyo skytree", "", 0));
	EXPECT_NE(0, ft_memcmp("tokyo skytree", "", 1));
}

TEST(ft_memcmp, boundary_value) {
	EXPECT_EQ(-1, ft_memcmp("tokyo skytree", "tokyo tower", 7));
	EXPECT_EQ(1, ft_memcmp("tokyo tower", "tokyo skytree", 7));
}

TEST(ft_memcmp, unique_value) {
	EXPECT_EQ(0, ft_memcmp((int []){1}, (int []){1}, 4));
	EXPECT_EQ(0, ft_memcmp((int []){1}, (char []){1, 0, 0, 3}, 3));
	EXPECT_EQ(0, ft_memcmp((int []){256}, (char []){0, 1, 0, 0}, 4));
	EXPECT_EQ(1, ft_memcmp((int []){2}, (int []){1}, 4));
	EXPECT_EQ(-1, ft_memcmp((int []){1}, (int []){2}, 4));
	EXPECT_EQ(1, ft_memcmp((int []){2}, (int []){1}, 1));
	EXPECT_EQ(-1, ft_memcmp((int []){1}, (int []){2}, 1));
}

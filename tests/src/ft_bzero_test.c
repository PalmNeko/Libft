
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_bzero, basic_usage) {
	char	value[12] = "11111111111";
	int		numbers[12] = {0};

	ft_bzero(value, sizeof(value));
	EXPECT_EQ(0, ft_memcmp(value, "\0\0\0\0\0\0\0\0\0\0\0", sizeof(value)));
	ft_memset(numbers, 'a', sizeof(numbers));
	ft_bzero(numbers, sizeof(numbers));
	EXPECT_EQ(0, ft_memcmp(numbers, (int []){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, sizeof(numbers)));
	ft_memset(value, 'a', sizeof(value));
	ft_bzero(value, 0);
	EXPECT_EQ(0, ft_memcmp(value, "aaaaaaaaaaaa", 12));
}

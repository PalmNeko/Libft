
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdio.h>

TEST(ft_memchr, basic_usage) {
	char	search_string[] = "abcdefghijklmn";
	EXPECT_EQ(search_string + 12, ft_memchr(search_string, 'm', sizeof(search_string)));
	EXPECT_EQ(search_string + 7, ft_memchr(search_string, 'h', sizeof(search_string)));
	EXPECT_EQ(search_string + 10, ft_memchr(search_string, 'k', sizeof(search_string)));
	EXPECT_EQ(search_string + 2, ft_memchr(search_string, 'c', sizeof(search_string)));
}

TEST(ft_memchr, boundary_test) {
	char	search_string[] = "abcdefghijklmn";

	EXPECT_EQ(search_string, ft_memchr(search_string, 'a', sizeof(search_string)));
	EXPECT_EQ(search_string + 13, ft_memchr(search_string, 'n', sizeof(search_string)));
	EXPECT_EQ(search_string + 14, ft_memchr(search_string, '\0', sizeof(search_string)));
	EXPECT_EQ(NULL, ft_memchr(search_string, '\0', sizeof(search_string) - 1));
	EXPECT_EQ(NULL, ft_memchr(search_string, 'a', 0));
	EXPECT_EQ(NULL, ft_memchr(search_string, 'z', sizeof(search_string)));
}

TEST(ft_memchr, error_check) {
	char	search_string[] = "abcdefghijklmn";

	EXPECT_EQ(NULL, ft_memchr(NULL, 'a', 0));
	EXPECT_EQ(NULL, ft_memchr(search_string, 'a', 0));
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_strincludes, basic_usage) {
	EXPECT_TRUE(ft_strincludes("abcdefg", "hhhhhhhhhhhhhhha"));
	EXPECT_TRUE(ft_strincludes("abcdefg", "hhhhhhhhhhhhhhhhhg"));
	EXPECT_TRUE(ft_strincludes("abcdefg", "aaaaaaaaaaahhhhhhhhhhhh"));
	EXPECT_TRUE(ft_strincludes((char []){1, 0xfe, 0}, (char []){1, 0xff, 0}));
	EXPECT_TRUE(ft_strincludes((char []){(char)0xff1, (char)0xfffe, 0}, (char []){(char)0xff1, (char)0xffff, 0}));
	EXPECT_TRUE(ft_strincludes((char []){1, 0xff, 0}, (char []){2, 0xff, 0}));
	EXPECT_TRUE(ft_strincludes((char []){(char)0xff1, (char)0xffff, 0}, (char []){(char)0xff2, (char)0xffff, 0}));
	EXPECT_FALSE(ft_strincludes("abcdefg", "\0"));
	EXPECT_FALSE(ft_strincludes("", "\0"));
	EXPECT_FALSE(ft_strincludes("", ""));
	EXPECT_FALSE(ft_strincludes("abc", "d"));
	EXPECT_FALSE(ft_strincludes("abc", ""));
	EXPECT_FALSE(ft_strincludes((char []){2, 0xfe, 0}, (char []){1, 0xff, 0}));
}



#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

static int	g_cnt;
static int	g_indexes[6];
static char	g_characters[6];

void	_iteri_function(unsigned int index, char *ptr)
{
	if (g_cnt >= 6)
		return ;
	g_characters[g_cnt] = *ptr;
	g_indexes[g_cnt] = index;
	g_cnt++;
}

TEST(ft_striteri, basic_usage) {
	ft_striteri("abcdef", _iteri_function);
	EXPECT_EQ('a', g_characters[0]);
	EXPECT_EQ('b', g_characters[1]);
	EXPECT_EQ('c', g_characters[2]);
	EXPECT_EQ('d', g_characters[3]);
	EXPECT_EQ('e', g_characters[4]);
	EXPECT_EQ('f', g_characters[5]);
	EXPECT_EQ(6, g_cnt);
	EXPECT_EQ(0, g_indexes[0]);
	EXPECT_EQ(1, g_indexes[1]);
	EXPECT_EQ(2, g_indexes[2]);
	EXPECT_EQ(3, g_indexes[3]);
	EXPECT_EQ(4, g_indexes[4]);
	EXPECT_EQ(5, g_indexes[5]);
}

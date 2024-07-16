
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>
#include <stdlib.h>

static int	g_cnt;
static unsigned int	g_indexes[6];

static char	_toupper_iteri(unsigned int index, char target)
{
	if (g_cnt >= 6)
		return ('\0');
	g_indexes[g_cnt] = index;
	g_cnt++;
	return (ft_toupper(target));
}

TEST(ft_strmapi, basic_usage) {
	char	*result;

	result = ft_strmapi("abcde", _toupper_iteri);
	EXPECT_STREQ("ABCDE", result);
	free(result);
	EXPECT_EQ((unsigned int)0, g_indexes[0]);
	EXPECT_EQ((unsigned int)1, g_indexes[1]);
	EXPECT_EQ((unsigned int)2, g_indexes[2]);
	EXPECT_EQ((unsigned int)3, g_indexes[3]);
	EXPECT_EQ((unsigned int)4, g_indexes[4]);
	EXPECT_EQ(5, g_cnt);
}

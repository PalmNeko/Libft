
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_split, basic_usage) {
	char	**splitted = NULL;
	int		i;

	splitted = ft_split("a,abc,,de,f", ',');
	EXPECT_STREQ("a", splitted[0]);
	EXPECT_STREQ("abc", splitted[1]);
	EXPECT_STREQ("de", splitted[2]);
	EXPECT_STREQ("f", splitted[3]);
	ASSERT_EQ(NULL, splitted[4]);
	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

TEST(ft_split, unique) {
	char	**splitted = NULL;
	int		i;

	splitted = ft_split(",,a,abc,,de,f,,", ',');
	EXPECT_STREQ("a", splitted[0]);
	EXPECT_STREQ("abc", splitted[1]);
	EXPECT_STREQ("de", splitted[2]);
	EXPECT_STREQ("f", splitted[3]);
	ASSERT_EQ(NULL, splitted[4]);
	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	splitted = ft_split(",,,,", ',');
	ASSERT_EQ(NULL, splitted[0]);
	i = 0;
	while (splitted[i] != NULL)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}
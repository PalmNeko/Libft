
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strrchr, basic_usage) {
	char	*src = "tabcabcdef";

	EXPECT_EQ(src + 10, ft_strrchr(src, '\0'));
	EXPECT_EQ(NULL, ft_strrchr(src, 'k'));
	EXPECT_EQ(src + 4, ft_strrchr(src, 'a'));
	EXPECT_EQ(src, ft_strrchr(src, 't'));
}


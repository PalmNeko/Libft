
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strtolower, basic_usage)
{
	char	base[] = "11BaSbd";

	EXPECT_STREQ("11basbd", ft_strtolower(base));
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strtoupper, basic_usage)
{
	char	base[] = "11BaSbd";

	EXPECT_STREQ("11BASBD", ft_strtoupper(base));
}

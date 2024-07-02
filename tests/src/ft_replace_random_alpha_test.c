
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_replace_random_alpha, basic_usage) {
	char		str[] = "abcdef";
	uint32_t	seed = ft_addr2uint32_t(str);

	ft_replace_random_alpha(str, 3, seed, 1);
	EXPECT_STRNE(str, "abcdef");
	if (ft_strcmp(str, "abcdef") == 0)
		ASSERT_EQ(seed, (unsigned int)0);
}


#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_atoi, simple_check)
{
	EXPECT_EQ(1230, ft_atoi("1230"));
}

TEST(ft_atoi, space_check)
{
	EXPECT_EQ(198273, ft_atoi(" 198273"));
	EXPECT_EQ(129387, ft_atoi("\n129387"));
	EXPECT_EQ(532987, ft_atoi("\r532987"));
	EXPECT_EQ(423874, ft_atoi("\t423874"));
	EXPECT_EQ(123897, ft_atoi("\f123897"));
	EXPECT_EQ(412897, ft_atoi("\v412897"));
	EXPECT_EQ(12894, ft_atoi("\r \n\t\f\v12894"));
}

TEST(ft_atoi, sign_check)
{
	EXPECT_EQ(19237, ft_atoi("19237"));
	EXPECT_EQ(+349857, ft_atoi("+349857"));
	EXPECT_EQ(-198273, ft_atoi("-198273"));
	EXPECT_EQ(429387, ft_atoi("429387"));
	EXPECT_EQ(+423874, ft_atoi("+423874"));
	EXPECT_EQ(-4298374, ft_atoi("-4298374"));
}

TEST(ft_atoi, combine_check)
{
	EXPECT_EQ(19237, ft_atoi(" \r +19237"));
	EXPECT_EQ(+349857, ft_atoi("\v\n+349857"));
	EXPECT_EQ(-198273, ft_atoi("   \r-198273"));
	EXPECT_EQ(429387, ft_atoi("  \f429387"));
	EXPECT_EQ(+423874, ft_atoi("\t\n+423874"));
	EXPECT_EQ(-4298374, ft_atoi("\r\f-4298374"));
}

#if LONG_MAX == 2147483647

TEST(ft_atoi, boundary_value)
{
	EXPECT_EQ(0, ft_atoi("0"));
	EXPECT_EQ((int)(LONG_MAX - 1), ft_atoi("2147483646"));
	EXPECT_EQ((int)(LONG_MAX), ft_atoi("2147483647"));
	EXPECT_EQ((int)(LONG_MAX), ft_atoi("2147483648"));
	EXPECT_EQ((int)(LONG_MAX), ft_atoi("9999999999999999999"));
	EXPECT_EQ((int)(LONG_MIN + 1), ft_atoi("-2147483647"));
	EXPECT_EQ((int)(LONG_MIN), ft_atoi("-2147483648"));
	EXPECT_EQ((int)(LONG_MIN), ft_atoi("-2147483649"));
	EXPECT_EQ((int)(LONG_MIN), ft_atoi("-9999999999999999999"));
}

#elif LONG_MAX == 9223372036854775807

TEST(ft_atoi, boundary_value)
{
	EXPECT_EQ(0, ft_atoi("0"));
	EXPECT_EQ((int)(LONG_MAX - 1), ft_atoi("9223372036854775806"));
	EXPECT_EQ((int)(LONG_MAX), ft_atoi("9223372036854775807"));
	EXPECT_EQ((int)(LONG_MAX), ft_atoi("9223372036854775808"));
	EXPECT_EQ((int)(LONG_MAX), ft_atoi("9999999999999999999"));
	EXPECT_EQ((int)(LONG_MIN + 1), ft_atoi("-9223372036854775807"));
	EXPECT_EQ((int)(LONG_MIN), ft_atoi("-9223372036854775808"));
	EXPECT_EQ((int)(LONG_MIN), ft_atoi("-9223372036854775809"));
	EXPECT_EQ((int)(LONG_MIN), ft_atoi("-9999999999999999999"));
}

else

TEST(ft_atoi, boundary_value)
{
	ASSERT_EQ("You have to write for your boundary_value tests","");
}

#endif
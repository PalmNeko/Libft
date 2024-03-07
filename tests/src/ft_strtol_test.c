
#include "tyctest.h"
#include "libft.h"
#include <limits.h>
#include <errno.h>

TEST(ft_strtol, simple_check)
{
	EXPECT_EQ(6, ft_strtol("110", NULL, 2));
	EXPECT_EQ(305, ft_strtol("gH", NULL, 18));
	EXPECT_EQ(46101, ft_strtol("zKl", NULL, 36));
}

TEST(ft_strtol, base_zero_check)
{
	EXPECT_EQ(15, ft_strtol("0xG", NULL, 0));
	EXPECT_EQ(4079661091, ft_strtol("0xf32aB023", NULL, 0));
	EXPECT_EQ(4285, ft_strtol("0123", NULL, 0));
	EXPECT_EQ(168674, ft_strtol("0511342", NULL, 0));
	EXPECT_EQ(195023, ft_strtol("195023", NULL, 0));
	EXPECT_EQ(3587302, ft_strtol("3587302", NULL, 0));
}

TEST(ft_strtol, endcheck)
{
	EXPECT_EQ(1027039, ft_strtol("fabdfk0123", NULL, 16));
	EXPECT_EQ(62250, ft_strtol("0xf32anb023", NULL, 0));
	EXPECT_EQ(342391, ft_strtol("012345678291278", NULL, 0));
	EXPECT_EQ(43007, ft_strtol("1237778", NULL, 8));
	EXPECT_EQ(19502, ft_strtol("19502a3", NULL, 0));
	EXPECT_EQ(3587302, ft_strtol("3587302b", NULL, 0));
}

TEST(ft_strtol, space_check)
{
	EXPECT_EQ(6, ft_strtol(" 111", NULL, 2));
	EXPECT_EQ(305, ft_strtol("\ngh", NULL, 18));
	EXPECT_EQ(46101, ft_strtol("\rzkl", NULL, 3));
	EXPECT_EQ(6, ft_strtol("\t111", NULL, 2));
	EXPECT_EQ(6, ft_strtol("\f111", NULL, 2));
	EXPECT_EQ(6, ft_strtol("\v111", NULL, 2));
	EXPECT_EQ(6, ft_strtol("\r \n\t\f\v111", NULL, 2));
}

TEST(ft_strtol, sign_check)
{
	EXPECT_EQ(6, ft_strtol("110", NULL, 2));
	EXPECT_EQ(6, ft_strtol("+110", NULL, 2));
	EXPECT_EQ(6, ft_strtol("-110", NULL, 2));
	EXPECT_EQ(6, ft_strtol("110", NULL, 2));
	EXPECT_EQ(6, ft_strtol("+110", NULL, 2));
	EXPECT_EQ(6, ft_strtol("-110", NULL, 2));
}

TEST(ft_strtol, endptr_check)
{
	char    *nptr;
	char    *endptr;

	nptr = "2432";
	ft_strtol(nptr, &endptr, 10);
	EXPECT_EQ(nptr + 4, endptr);
	nptr = "2432a";
	ft_strtol(nptr, &endptr, 10);
	EXPECT_EQ(nptr + 4, endptr);
	nptr = "a2432";
	ft_strtol(nptr, &endptr, 10);
	EXPECT_EQ(nptr, endptr);
}

TEST(ft_strtol, boundary_value_64bit)
{
	EXPECT_EQ(0, ft_strtol("0", NULL, 10));
	EXPECT_EQ(0, ft_strtol("0", NULL, 10));
	errno = 0;
	EXPECT_EQ(LONG_MAX - 1, ft_strtol("9223372036854775806", NULL, 10));
	EXPECT_EQ(LONG_MAX, ft_strtol("9223372036854775807", NULL, 10));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MAX, ft_strtol("9223372036854775808", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_strtol("9999999999999999999", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MIN + 1, ft_strtol("-9223372036854775807", NULL, 10));
	EXPECT_EQ(LONG_MIN, ft_strtol("-9223372036854775808", NULL, 10));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MIN, ft_strtol("-9223372036854775809", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MIN, ft_strtol("-9999999999999999999", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
}

TEST(ft_strtol, errno_check)
{
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_strtol("9223372036854775807", NULL, 10));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MAX, ft_strtol("9223372036854775808", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MAX, ft_strtol("9999999999999999999", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MIN, ft_strtol("-9223372036854775808", NULL, 10));
	EXPECT_EQ(0, errno);
	EXPECT_EQ(LONG_MIN, ft_strtol("-9223372036854775809", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
	EXPECT_EQ(LONG_MIN, ft_strtol("-9999999999999999999", NULL, 10));
	EXPECT_EQ(ERANGE, errno);
	errno = 0;
}

TEST(ft_strtol, not_in_C99)
{
	EXPECT_EQ(0, ft_strtol(NULL, NULL, 2));
	EXPECT_EQ(EINVAL, errno);
}


#include "tyctest.h"
#include "libft.h"
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#include <stdlib.h>

TEST(ft_write_aligned_right, basic_usage) {
	int		outfd;
	int		infd;
	char	read_buf[30];
	ssize_t	read_len;
	ssize_t	write_len;
	char	template[30];

	ft_strlcpy(template, "tmp.test.XXXXXX", 30);
	outfd = ft_mkostemp(template, 0);
	ASSERT_NE(outfd, -1);
	infd = open(template, O_RDONLY);
	ASSERT_NE(infd, -1);
	unlink(template);
	write_len = ft_write_aligned_right(outfd, "123", 3, 5);
	EXPECT_EQ(write_len, 5);
	read_len = read(infd, read_buf, 10);
	EXPECT_EQ(read_len, 5);
	EXPECT_EQ(read_buf[0], ' ');
	EXPECT_EQ(read_buf[1], ' ');
	EXPECT_EQ(read_buf[2], '1');
	EXPECT_EQ(read_buf[3], '2');
	EXPECT_EQ(read_buf[4], '3');
	close(outfd);
	close(infd);
}

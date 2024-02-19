/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 18:05:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 18:18:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int	_ft_putnbr_fd_test(int n);

void	ft_putnbr_fd_test(void)
{
	assert(_ft_putnbr_fd_test(-12));
	assert(_ft_putnbr_fd_test(12));
	assert(_ft_putnbr_fd_test(0));
	assert(_ft_putnbr_fd_test(INT_MAX));
	assert(_ft_putnbr_fd_test(INT_MIN));
}

int	_ft_putnbr_fd_test(int n)
{
	int		fd;
	int		cmp_result;
	char	s[15];
	char	*to_be;
	ssize_t	read_size;

	cmp_result = -1;
	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	assert(fd != -1);
	ft_putnbr_fd(n, fd);
	lseek(fd, SEEK_SET, 0);
	read_size = read(fd, s, 14);
	assert(read_size != -1);
	s[read_size] = '\0';
	to_be = ft_itoa(n);
	assert(to_be != NULL);
	cmp_result = strncmp(s, to_be, ft_strlen(to_be));
	if (cmp_result != 0)
		printf("%s, %s\n", s, to_be);
	assert(close(fd) != -1);
	free(to_be);
	return (cmp_result == 0);
}

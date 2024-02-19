/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:37:42 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 17:46:33 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putstr_fd_test(void)
{
	int		fd;
	char	*s;

	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	assert(fd != -1);
	ft_putstr_fd("ab", fd);
	lseek(fd, SEEK_SET, 0);
	s = (char []){0, 0, 0};
	read(fd, s, 3);
	assert(memcmp(s, "ab", 3) == 0);
	return ;
}

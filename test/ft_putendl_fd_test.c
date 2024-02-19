/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:51:55 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 17:55:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putendl_fd_test(void)
{
	int		fd;
	char	*s;

	fd = open("tmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	assert(fd != -1);
	ft_putendl_fd("a", fd);
	lseek(fd, SEEK_SET, 0);
	s = (char []){0, 0, 0};
	read(fd, s, 2);
	assert(memcmp(s, "a\n", 3) == 0);
	return ;
}

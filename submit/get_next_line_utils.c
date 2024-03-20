/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:14:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/04 12:40:55 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlenchr(char const *s, char find)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != find)
		len++;
	return (len);
}

void	*free_manager(char **str1)
{
	if (str1 != NULL)
	{
		free(*str1);
		*str1 = NULL;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, char find)
{
	while (*s != '\0')
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (NULL);
}

char	*read_str(int fd)
{
	char	*buf;
	ssize_t	read_result;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_result = read(fd, buf, BUFFER_SIZE);
	if (read_result < 0)
		return (free_manager(&buf));
	buf[read_result] = '\0';
	return (buf);
}

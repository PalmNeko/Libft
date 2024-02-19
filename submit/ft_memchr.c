/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:35:21 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:29:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sp;
	unsigned char	value;
	size_t			index;

	sp = (unsigned char *)s;
	value = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (sp[index] == value)
			return (sp + index);
		index++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:26:53 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 16:30:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		copy_count;
	char		*dst_p;
	const char	*src_p;

	if (dst == NULL && src == NULL)
		return (dst);
	dst_p = dst;
	src_p = src;
	copy_count = 0;
	while (copy_count < n)
	{
		dst_p[copy_count] = src_p[copy_count];
		copy_count++;
	}
	return (dst);
}

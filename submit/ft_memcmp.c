/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:51:38 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:28:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1p;
	const unsigned char	*s2p;
	size_t				count;

	s1p = s1;
	s2p = s2;
	count = 0;
	while (count < n)
	{
		if (s1p[count] != s2p[count])
			return ((s1p[count] - s2p[count]));
		count++;
	}
	return (0);
}

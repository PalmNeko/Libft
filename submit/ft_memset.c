/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:52:53 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:28:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bp;
	unsigned char	value;
	size_t			set_count;

	bp = b;
	value = c;
	set_count = 0;
	while (set_count < len)
	{
		bp[set_count] = value;
		set_count++;
	}
	return (b);
}

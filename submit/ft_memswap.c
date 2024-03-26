/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:36:47 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/14 22:36:47 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 * @brief swap data valu1 and valu2
 * @param value1 one value
 * @param value2 one value
 * @param size size value1 and value2 [byte]
 * @return return 0 if success. return -1 if occured error.
 * never occur error, so return value is useless.
 */
int	ft_memswap(void *value1, void *value2, size_t size)
{
	size_t			index;
	unsigned char	*v1;
	unsigned char	*v2;

	v1 = value1;
	v2 = value2;
	index = 0;
	while (index < size)
	{
		if (ft_memcmp(v1, v2, size) != 0)
		{
			v1[index] ^= v2[index];
			v2[index] ^= v1[index];
			v1[index] ^= v2[index];
		}
		index += 1;
	}
	return (0);
}

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
 */
int	ft_memswap(void *value1, void *value2, size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		return (-1);
	ft_memcpy(tmp, value1, size);
	ft_memcpy(value1, value2, size);
	ft_memcpy(value2, tmp, size);
	free(tmp);
	return (0);
}
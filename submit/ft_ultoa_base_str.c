/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:33:21 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/09 14:33:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

char	*ft_ultoa_base_str(unsigned long n, const char *base_str)
{
	char		num_str[70];
	int			base;
	size_t		index;

	base = ft_strlen(base_str);
	index = 0;
	if (n == 0)
		num_str[index++] = '0';
	while (n != 0)
	{
		num_str[index++] = base_str[ft_abs(n % base)];
		n /= base;
	}
	num_str[index] = '\0';
	ft_strrev(num_str);
	return (ft_strdup(num_str));
}

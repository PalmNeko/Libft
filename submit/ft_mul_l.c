/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mul_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:41:08 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 18:42:23 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <limits.h>

long	ft_mul_l(long value, long mul_value)
{
	if (mul_value != 0 && value > LONG_MAX / mul_value)
	{
		errno = ERANGE;
		return (LONG_MAX);
	}
	else if (mul_value != 0 && value < LONG_MIN / mul_value)
	{
		errno = ERANGE;
		return (LONG_MIN);
	}
	return (value * mul_value);
}

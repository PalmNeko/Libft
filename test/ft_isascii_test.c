/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:29:36 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/24 18:34:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_isascii_test(void)
{
	assert(ft_isascii(0 - 1) == isascii(0 - 1));
	assert(ft_isascii(0) == isascii(0));
	assert(ft_isascii(0177) == isascii(0177));
	assert(ft_isascii(0177 + 1) == isascii(0177 + 1));
	return ;
}

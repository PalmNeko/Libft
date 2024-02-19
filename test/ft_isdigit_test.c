/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:21:41 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/24 17:49:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_isdigit_test(void)
{
	assert(ft_isdigit('0' - 1) == isdigit('0' - 1));
	assert(ft_isdigit('0') == isdigit('0'));
	assert(ft_isdigit('1') == isdigit('1'));
	assert(ft_isdigit('9') == isdigit('9'));
	assert(ft_isdigit('9' + 1) == isdigit('9' + 1));
	assert(ft_isdigit(0) == isdigit(0));
	assert(ft_isdigit(128) == isdigit(127));
	assert(ft_isdigit(-128) == isdigit(-128));
	return ;
}

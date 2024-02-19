/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:23:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/27 16:51:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_isprint_test(void)
{
	assert(ft_isprint(' ' - 1) == isprint(' ' - 1));
	assert(ft_isprint(' ') == isprint(' '));
	assert(ft_isprint('!') == isprint('!'));
	assert(ft_isprint('~') == isprint('~'));
	assert(ft_isprint('~' + 1) == isprint('~' + 1));
	assert(ft_isprint(0) == isprint(0));
	assert(ft_isprint(128) == isprint(127));
	assert(ft_isprint(-128) == isprint(-128));
}

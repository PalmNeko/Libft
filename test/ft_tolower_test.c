/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:08:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/28 18:09:28 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_tolower_test(void)
{
	assert(ft_tolower('a' - 1) == tolower('a' - 1));
	assert(ft_tolower('a') == tolower('a'));
	assert(ft_tolower('z') == tolower('z'));
	assert(ft_tolower('z' + 1) == tolower('z' + 1));
	assert(ft_tolower('A' - 1) == tolower('A' - 1));
	assert(ft_tolower('A') == tolower('A'));
	assert(ft_tolower('Z') == tolower('Z'));
	assert(ft_tolower('Z' + 1) == tolower('Z' + 1));
	assert(ft_tolower(0) == tolower(0));
	assert(ft_tolower(127) == tolower(127));
	assert(ft_tolower(-128) == tolower(-128));
	return ;
}

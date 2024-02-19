/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:56:17 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/28 19:33:05 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_toupper_test(void)
{
	assert(ft_toupper('a' - 1) == toupper('a' - 1));
	assert(ft_toupper('a') == toupper('a'));
	assert(ft_toupper('z') == toupper('z'));
	assert(ft_toupper('z' + 1) == toupper('z' + 1));
	assert(ft_toupper('A' - 1) == toupper('A' - 1));
	assert(ft_toupper('A') == toupper('A'));
	assert(ft_toupper('Z') == toupper('Z'));
	assert(ft_toupper('Z' + 1) == toupper('Z' + 1));
	assert(ft_toupper(0) == toupper(0));
	assert(ft_toupper(127) == toupper(127));
	assert(ft_toupper(-128) == toupper(-128));
	return ;
}

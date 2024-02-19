/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:48:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/28 18:10:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_isalpha_test(void)
{
	assert(ft_isalpha('a' - 1) == isalpha('a' - 1));
	assert(ft_isalpha('a') == isalpha('a'));
	assert(ft_isalpha('z') == isalpha('z'));
	assert(ft_isalpha('z' + 1) == isalpha('z' + 1));
	assert(ft_isalpha('A' - 1) == isalpha('A' - 1));
	assert(ft_isalpha('A') == isalpha('A'));
	assert(ft_isalpha('Z') == isalpha('Z'));
	assert(ft_isalpha('Z' + 1) == isalpha('Z' + 1));
	assert(ft_isalpha(0) == isalpha(0));
	assert(ft_isalpha(127) == isalpha(127));
	assert(ft_isalpha(-128) == isalpha(-128));
	return ;
}

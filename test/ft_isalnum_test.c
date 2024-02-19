/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:45:41 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/28 18:10:10 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <ctype.h>

void	ft_isalnum_test_num(void);
void	ft_isalnum_test_alpha(void);
void	ft_isalnum_test_other(void);

void	ft_isalnum_test(void)
{
	ft_isalnum_test_num();
	ft_isalnum_test_alpha();
	ft_isalnum_test_other();
	return ;
}

void	ft_isalnum_test_num(void)
{
	assert(ft_isalnum('0' - 1) == isalnum('0' - 1));
	assert(ft_isalnum('0') == isalnum('0'));
	assert(ft_isalnum('1') == isalnum('1'));
	assert(ft_isalnum('9') == isalnum('9'));
	assert(ft_isalnum('9' + 1) == isalnum('9' + 1));
	return ;
}

void	ft_isalnum_test_alpha(void)
{
	assert(ft_isalnum('a' - 1) == isalnum('a' - 1));
	assert(ft_isalnum('a') == isalnum('a'));
	assert(ft_isalnum('z') == isalnum('z'));
	assert(ft_isalnum('z' + 1) == isalnum('z' + 1));
	assert(ft_isalnum('A' - 1) == isalnum('A' - 1));
	assert(ft_isalnum('A') == isalnum('A'));
	assert(ft_isalnum('Z') == isalnum('Z'));
	assert(ft_isalnum('Z' + 1) == isalnum('Z' + 1));
	return ;
}

void	ft_isalnum_test_other(void)
{
	assert(ft_isalpha(0) == isalpha(0));
	assert(ft_isalpha(127) == isalpha(127));
	assert(ft_isalpha(-128) == isalpha(-128));
	return ;
}

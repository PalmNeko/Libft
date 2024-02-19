/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:44:32 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/10 15:39:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

int	_ft_strchr_test(char *src, int search);

void	ft_strchr_test(void)
{
	assert(_ft_strchr_test("abcdefg", 'c'));
	assert(_ft_strchr_test("abcdefg", '\0'));
	assert(_ft_strchr_test("abcdefg", 'a'));
	assert(_ft_strchr_test("abcdefg", 'g'));
	assert(_ft_strchr_test("", 'g'));
	assert(_ft_strchr_test("", '\0'));
	assert(_ft_strchr_test("tripouille", 't' + 256));
}

int	_ft_strchr_test(char *src, int search)
{
	return (ft_strchr(src, search) == strchr(src, search));
}

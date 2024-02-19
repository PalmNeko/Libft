/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:57:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 18:51:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int	_ft_strnstr_test(const char *str, const char *search, size_t len);

void	ft_strnstr_test(void)
{
	assert(_ft_strnstr_test("abcdef", "abc", 0));
	assert(_ft_strnstr_test("abcdef", "abc", 1));
	assert(_ft_strnstr_test("abcdef", "abc", 2));
	assert(_ft_strnstr_test("abcdef", "abc", 3));
	assert(_ft_strnstr_test("abcdef", "abc", 4));
	assert(_ft_strnstr_test("abcdef", "abc", 6));
	assert(_ft_strnstr_test("abcdef", "abc", 7));
	assert(_ft_strnstr_test("abcdef", "abc", 8));
	assert(_ft_strnstr_test("abcdef", "abc", 9));
	assert(_ft_strnstr_test("abcdef", "abc", 10));
	assert(_ft_strnstr_test("", "abc", 0));
	assert(_ft_strnstr_test("", "abc", 1));
	assert(_ft_strnstr_test("", "abc", 2));
	assert(_ft_strnstr_test("", "abc", 3));
	assert(_ft_strnstr_test("", "abc", 4));
	assert(_ft_strnstr_test("abc", "", 0));
	assert(_ft_strnstr_test("abc", "", 1));
	assert(_ft_strnstr_test("abc", "", 2));
	assert(_ft_strnstr_test("abc", "", 3));
	assert(_ft_strnstr_test("abc", "", 4));
}

int	_ft_strnstr_test(const char *str, const char *search, size_t len)
{
	char	*ret_ft;
	char	*ret_ori;

	ret_ft = ft_strnstr(str, search, len);
	ret_ori = strnstr(str, search, len);
	if (ret_ft != ret_ori)
		printf("Assertion failed - ret: ft: %p, ori: %p\n", ret_ft, ret_ori);
	return (ret_ft == ret_ori);
}

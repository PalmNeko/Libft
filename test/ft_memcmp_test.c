/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:55:03 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 15:58:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>

int	_ft_memcmp_test(const void *s1, const void *s2, size_t n);

void	ft_memcmp_test(void)
{
	assert(_ft_memcmp_test("", "", 0));
	assert(_ft_memcmp_test("", "", 1));
	assert(_ft_memcmp_test("abcdef", "abde", 0));
	assert(_ft_memcmp_test("abcdef", "abde", 1));
	assert(_ft_memcmp_test("abcdef", "abde", 2));
	assert(_ft_memcmp_test("abcdef", "abde", 3));
	assert(_ft_memcmp_test("abcdef", "abde", 4));
	assert(_ft_memcmp_test("abcdef", "abde", 5));
	assert(_ft_memcmp_test("abcdef", "abde", 6));
	assert(_ft_memcmp_test("abcdef", "abde", 7));
}

int	_ft_memcmp_test(const void *s1, const void *s2, size_t n)
{
	return (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n));
}

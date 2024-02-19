/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:40:27 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 18:36:40 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int	_ft_memchr_test(const void *s, int c, size_t n);

void	ft_memchr_test(void)
{
	assert(_ft_memchr_test("abc", 'c', 0));
	assert(_ft_memchr_test("abc", 'c', 1));
	assert(_ft_memchr_test("abc", 'c', 2));
	assert(_ft_memchr_test("abc", 'c', 3));
	assert(_ft_memchr_test("abc", 'c', 4));
	assert(_ft_memchr_test("abc", '\0', 0));
	assert(_ft_memchr_test("abc", '\0', 1));
	assert(_ft_memchr_test("abc", '\0', 2));
	assert(_ft_memchr_test("abc", '\0', 3));
	assert(_ft_memchr_test("abc", '\0', 4));
}

int	_ft_memchr_test(const void *s, int c, size_t n)
{
	void	*result_ft;
	void	*result_original;

	result_ft = ft_memchr(s, c, n);
	result_original = memchr(s, c, n);
	if (result_ft != result_original)
		fprintf(stderr, "Assertion failed - debug: your: %p, original: %p\n",
			result_ft, result_original);
	return (result_ft == result_original);
	return (ft_memchr(s, c, n) == memchr(s, c, n));
}

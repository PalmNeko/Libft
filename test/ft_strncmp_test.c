/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:53:30 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 15:29:18 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>

int	_ft_strncmp_test(char *s1, char *s2, size_t n);

void	ft_strncmp_test(void)
{
	assert(_ft_strncmp_test("", "", 0));
	assert(_ft_strncmp_test("", "", 1));
	assert(_ft_strncmp_test("abcdef", "abde", 0));
	assert(_ft_strncmp_test("abcdef", "abde", 1));
	assert(_ft_strncmp_test("abcdef", "abde", 2));
	assert(_ft_strncmp_test("abcdef", "abde", 3));
	assert(_ft_strncmp_test("abcdef", "abde", 4));
	assert(_ft_strncmp_test("abcdef", "abde", 5));
	assert(_ft_strncmp_test("abcdef", "abde", 6));
}

int	_ft_strncmp_test(char *s1, char *s2, size_t n)
{
	return (ft_strncmp(s1, s2, n) == strncmp(s1, s2, n));
}

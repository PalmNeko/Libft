/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:43:54 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/05 19:46:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int	_ft_substr_test(char const *str, unsigned int start, size_t len);

void	ft_substr_test(void)
{
	assert(_ft_substr_test("123", 1, 2));
	assert(_ft_substr_test("123", 0, 3));
	assert(_ft_substr_test("123", 4, 1));
	assert(_ft_substr_test("123", 5, 1));
	assert(_ft_substr_test("123", 2, 1000));
	return ;
}

int	_ft_substr_test(char const *str, unsigned int start, size_t len)
{
	char	*sub;
	char	*dup;
	int		cmp_result;

	sub = ft_substr(str, start, len);
	if (sub == NULL)
		return (0);
	if (start < strlen(str))
		dup = strndup(str + start, len);
	else
		dup = strndup(str + strlen(str), len);
	if (sub == NULL)
		return (0);
	cmp_result = strcmp(sub, dup);
	if (cmp_result != 0)
		fprintf(stderr, "sub: %s, dup: %s\n", sub, dup);
	free(dup);
	free(sub);
	return (cmp_result == 0);
}

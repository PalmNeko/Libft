/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:23:36 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/10 15:51:46 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int	_ft_strlcpy_test(char *str, size_t size);

void	ft_strlcpy_test(void)
{
	assert(0 == _ft_strlcpy_test("0123", 0));
	assert(0 == _ft_strlcpy_test("0123", 1));
	assert(0 == _ft_strlcpy_test("0123", 3));
	assert(0 == _ft_strlcpy_test("0123", 4));
	assert(0 == _ft_strlcpy_test("0123", 5));
	assert(0 == _ft_strlcpy_test("0123", 6));
	assert(0 == _ft_strlcpy_test("0123", 0));
	return ;
}

int	_ft_strlcpy_test(char *str, size_t size)
{
	char	*str_ft;
	char	*str_original;
	int		cmp_result;

	str_original = NULL;
	str_ft = (char *)malloc(sizeof(char) * size);
	if (str_ft != NULL)
		str_original = (char *)malloc(sizeof(char) * size);
	cmp_result = -1;
	if (str_ft != NULL && str_original != NULL)
	{
		if (ft_strlcpy(str_ft, str, size) == strlcpy(str_original, str, size))
			cmp_result = memcmp(str_ft, str_original, size);
		else
			cmp_result = -1;
	}
	free(str_ft);
	free(str_original);
	return (cmp_result);
}

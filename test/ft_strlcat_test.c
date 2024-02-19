/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:00:05 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/11 13:49:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include <stdio.h>

int	_ft_strlcat_test(char *dest, char *str, size_t size);

void	ft_strlcat_test(void)
{
	assert(0 == _ft_strlcat_test("123", "0123", 0));
	assert(0 == _ft_strlcat_test("123", "0123", 1));
	assert(0 == _ft_strlcat_test("123", "0123", 3));
	assert(0 == _ft_strlcat_test("123", "0123", 4));
	assert(0 == _ft_strlcat_test("123", "0123", 5));
	assert(0 == _ft_strlcat_test("123", "0123", 6));
	return ;
}

int	_ft_strlcat_test(char *dest, char *str, size_t size)
{
	char	*str_ft;
	char	*str_original;
	int		cmp_result;

	str_original = NULL;
	str_ft = (char *)calloc((size + 10), sizeof(char));
	if (str_ft != NULL)
		str_original = (char *)calloc((size + 10), sizeof(char));
	cmp_result = -1;
	if (str_ft != NULL && str_original != NULL)
	{
		strlcpy(str_ft, dest, size + 10);
		strlcpy(str_original, dest, size + 10);
		if (ft_strlcat(str_ft, str, size) == strlcat(str_original, str, size))
			cmp_result = memcmp(str_ft, str_original, size + 10);
		else
			cmp_result = -1;
		if (cmp_result != 0)
			fprintf(stderr, "%s , %s\n", str_ft, str_original);
	}
	free(str_ft);
	free(str_original);
	return (cmp_result);
}

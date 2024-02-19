/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:40:14 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 17:32:06 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int	_ft_memcpy_test(char *str, size_t len);

void	ft_memcpy_test(void)
{
	assert(0 == _ft_memcpy_test("0123", 3));
	assert(0 == _ft_memcpy_test("0123", 4));
	assert(0 == _ft_memcpy_test("0123", 5));
	return ;
}

int	_ft_memcpy_test(char *str, size_t len)
{
	char	*str_ft;
	char	*str_original;
	int		cmp_result;

	str_original = NULL;
	str_ft = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	if (str_ft != NULL)
		str_original = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	cmp_result = 0;
	if (str_ft != NULL && str_original != NULL)
	{
		ft_memcpy(str_ft, str, len);
		memcpy(str_original, str, len);
		cmp_result = memcmp(str_ft, str_original, strlen(str) + 1);
		cmp_result |= memcmp(str_ft, str_original, len);
	}
	free(str_ft);
	free(str_original);
	return (cmp_result);
}

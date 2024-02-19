/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:59:21 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 17:29:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int	_ft_memset_test(char *str, int set_val, size_t len);

void	ft_memset_test(void)
{
	assert(0 == _ft_memset_test("0123", 'A', 3));
	assert(0 == _ft_memset_test("0123", 'A', 4));
	assert(0 == _ft_memset_test("0123", 'A', 5));
	return ;
}

int	_ft_memset_test(char *str, int set_val, size_t len)
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
		strcpy(str_ft, str);
		strcpy(str_original, str);
		if (ft_memset(str_ft, set_val, len) == str_ft
			&& memset(str_original, set_val, len) == str_original)
		{
			cmp_result = strncmp(str_ft, str_original, strlen(str) + 1);
			cmp_result |= strncmp(str_ft, str_original, len);
		}
		else
			cmp_result = -1;
	}
	free(str_ft);
	free(str_original);
	return (cmp_result);
}

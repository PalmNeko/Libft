/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:07 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 17:31:24 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <strings.h>
#include <assert.h>
#include <stdlib.h>

int	_ft_bzero_test(char *str, size_t len);

void	ft_bzero_test(void)
{
	assert(0 == _ft_bzero_test("0123", 3));
	assert(0 == _ft_bzero_test("0123", 4));
	assert(0 == _ft_bzero_test("0123", 5));
	return ;
}

int	_ft_bzero_test(char *str, size_t len)
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
		ft_bzero(str_ft, len);
		bzero(str_original, len);
		cmp_result = memcmp(str_ft, str_original, strlen(str) + 1);
		cmp_result |= memcmp(str_ft, str_original, len);
	}
	free(str_ft);
	free(str_original);
	return (cmp_result);
}

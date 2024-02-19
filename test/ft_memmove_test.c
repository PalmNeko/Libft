/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:24:24 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/29 18:10:45 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int	_ft_memmove_test(char *s, size_t src_offset, size_t dst_offset, size_t len);

void	ft_memmove_test(void)
{
	assert(0 == _ft_memmove_test("abcdefghijklmnopqrstu", 1, 0, 2));
	assert(0 == _ft_memmove_test("abcdefghijklmnopqrstu", 0, 1, 2));
	return ;
}

int	_ft_memmove_test(char *s, size_t src_offset, size_t dst_offset, size_t len)
{
	char	*str_ft;
	char	*str_original;
	int		cmp_result;

	str_original = NULL;
	str_ft = (char *)malloc(sizeof(char) * (strlen(s) + 1));
	if (str_ft != NULL)
		str_original = (char *)malloc(sizeof(char) * (strlen(s) + 1));
	cmp_result = 0;
	if (str_ft != NULL && str_original != NULL)
	{
		strcpy(str_ft, s);
		strcpy(str_original, s);
		memmove(str_original + src_offset, str_original + dst_offset, len);
		ft_memmove(str_ft + src_offset, str_ft + dst_offset, len);
		cmp_result = memcmp(str_ft, str_original, strlen(s) + 1);
		cmp_result |= memcmp(str_ft, str_original, len);
	}
	free(str_ft);
	free(str_original);
	return (cmp_result);
}

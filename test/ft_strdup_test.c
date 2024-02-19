/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:26:17 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/30 16:56:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	_ft_strdup_test(const char *str);

void	ft_strdup_test(void)
{
	assert(_ft_strdup_test(""));
	assert(_ft_strdup_test("a"));
	assert(_ft_strdup_test("ab"));
	assert(_ft_strdup_test("abc"));
	assert(_ft_strdup_test("abcdefghijklmnopqrstuvwxyz"));
}

int	_ft_strdup_test(const char *str)
{
	char	*copy_ft;
	char	*copy_original;
	int		cmp_result;

	copy_ft = NULL;
	copy_original = NULL;
	copy_ft = ft_strdup(str);
	if (copy_ft != NULL)
		copy_original = strdup(str);
	cmp_result = -1;
	if (copy_ft != NULL && copy_original != NULL)
	{
		cmp_result = strcmp(copy_ft, copy_original);
		cmp_result |= copy_ft == str;
	}
	free(copy_ft);
	free(copy_original);
	return (cmp_result == 0);
}

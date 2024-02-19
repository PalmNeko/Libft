/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:05:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/11 16:07:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	_ft_calloc_test(size_t count, size_t size);

void	ft_calloc_test(void)
{
	assert(_ft_calloc_test(0, 0));
	assert(_ft_calloc_test(0, 1));
	assert(_ft_calloc_test(1, 0));
	free(NULL);
	assert(_ft_calloc_test(1, 1));
	assert(_ft_calloc_test(INT_MAX, INT_MAX));
	assert(_ft_calloc_test(INT_MIN, INT_MIN));
	return ;
}

int	_ft_calloc_test(size_t count, size_t size)
{
	void	*ft;
	void	*original;
	int		cmp_result;

	cmp_result = -1;
	ft = ft_calloc(count, size);
	original = calloc(count, size);
	if (ft == NULL && original == NULL)
		cmp_result = 0;
	else if (ft != NULL && original != NULL)
		cmp_result = memcmp(ft, original, count * size);
	else
		cmp_result = -1;
	free(ft);
	free(original);
	return (cmp_result == 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:50:48 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 15:38:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	_ft_itoa_test(int n, char const *to_be);

void	ft_itoa_test(void)
{
	assert(_ft_itoa_test(-12, "-12"));
	assert(_ft_itoa_test(12, "12"));
	assert(_ft_itoa_test(0, "0"));
	assert(_ft_itoa_test(INT_MAX, "2147483647"));
	assert(_ft_itoa_test(INT_MIN, "-2147483648"));
	return ;
}

int	_ft_itoa_test(int n, char const *to_be)
{
	int		cmp_result;
	char	*str;

	str = ft_itoa(n);
	if (str == NULL)
		return (0);
	cmp_result = strcmp(str, to_be);
	if (cmp_result != 0)
		printf("%s, %s\n", str, to_be);
	free(str);
	return (cmp_result == 0);
}

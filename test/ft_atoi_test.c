/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:23:31 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/30 11:45:37 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int	_ft_atoi_test(const char *str);

void	ft_atoi_test(void)
{
	assert(_ft_atoi_test(""));
	assert(_ft_atoi_test(" "));
	assert(_ft_atoi_test("+"));
	assert(_ft_atoi_test("ab"));
	assert(_ft_atoi_test(" ab"));
	assert(_ft_atoi_test("-ab"));
	assert(_ft_atoi_test("+-123abc"));
	assert(_ft_atoi_test("--123abc"));
	assert(_ft_atoi_test("\t\n\v\f -123abc"));
	assert(_ft_atoi_test("\t\n\v\f 0123abc"));
	assert(_ft_atoi_test("\t\n\v\f 00123abc"));
	assert(_ft_atoi_test("0"));
	assert(_ft_atoi_test("-0"));
	assert(_ft_atoi_test("+0"));
	assert(_ft_atoi_test("2147483647"));
	assert(_ft_atoi_test("-2147483648"));
	assert(_ft_atoi_test("9223372036854775807"));
	assert(_ft_atoi_test("9223372036854775808"));
	assert(_ft_atoi_test("-9223372036854775809"));
	return ;
}

int	_ft_atoi_test(const char *str)
{
	long	value_ft;
	long	value_original;

	value_ft = ft_atoi(str);
	value_original = atoi(str);
	if (value_ft != value_original)
		fprintf(stderr, "your: %ld, orignal: %ld\n", value_ft, value_original);
	return (value_ft == value_original);
}

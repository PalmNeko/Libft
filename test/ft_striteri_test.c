/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:24:58 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 16:56:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	_ft_striteri_test(char *s, char const *to_be);

void	ft_striteri_test(void)
{
	assert(_ft_striteri_test("", ""));
	assert(_ft_striteri_test("abcdefg", "aBcDeFg"));
	assert(_ft_striteri_test("AaAaAaA", "aAaAaAa"));
}

static void	write_even_lower_odd_upper(unsigned int index, char *c)
{
	if (index % 2 == 0)
		*c = ft_tolower(*c);
	else
		*c = ft_toupper(*c);
}

int	_ft_striteri_test(char *s, char const *to_be)
{
	int		cmp_result;
	char	*copy;

	copy = ft_strdup(s);
	ft_striteri(copy, write_even_lower_odd_upper);
	cmp_result = strcmp(copy, to_be);
	if (cmp_result != 0)
		printf("%s, %s\n", copy, to_be);
	free(copy);
	return (cmp_result == 0);
}

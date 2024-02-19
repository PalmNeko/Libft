/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:53:36 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/08 16:12:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	_ft_strmapi_test(char const *s, const char *to_be);

void	ft_strmapi_test(void)
{
	assert(_ft_strmapi_test("", ""));
	assert(_ft_strmapi_test("abcdefg", "aBcDeFg"));
	assert(_ft_strmapi_test("AaAaAaA", "aAaAaAa"));
}

static char	even_lower_odd_upper(unsigned int index, char alpha)
{
	if (index % 2 == 0)
		return (ft_tolower(alpha));
	else
		return (ft_toupper(alpha));
}

int	_ft_strmapi_test(char const *s, const char *to_be)
{
	int		cmp_result;
	char	*str;

	str = ft_strmapi(s, even_lower_odd_upper);
	if (str == NULL)
		return (0);
	cmp_result = strcmp(str, to_be);
	if (cmp_result != 0)
		printf("%s, %s\n", str, to_be);
	free(str);
	return (cmp_result == 0);
}

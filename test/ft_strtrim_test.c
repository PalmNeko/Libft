/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:36:18 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/06 17:05:02 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	_ft_strtrim_test(char const *s1, char const *set, const char *to_be);

void	ft_strtrim_test(void)
{
	assert(_ft_strtrim_test("112233", "2", "112233"));
	assert(_ft_strtrim_test("112233", "12", "33"));
	assert(_ft_strtrim_test("112233", "32", "11"));
	assert(_ft_strtrim_test("112233", "13", "22"));
	return ;
}

int	_ft_strtrim_test(char const *s1, char const *set, const char *to_be)
{
	int		cmp_result;
	char	*trim;

	cmp_result = -1;
	trim = ft_strtrim(s1, set);
	if (trim != NULL)
	{
		cmp_result = strcmp(trim, to_be);
		if (cmp_result != 0)
			printf("trim %s, to be: %s\n", trim, to_be);
	}
	free(trim);
	return (cmp_result == 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:15:08 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/11 16:48:30 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	_ft_strjoin_test(char const *s1, char const *s2, char const *to_be);

void	ft_strjoin_test(void)
{
	assert(_ft_strjoin_test("a", "b", "ab"));
	assert(_ft_strjoin_test("ab", "b", "abb"));
	assert(_ft_strjoin_test("a", "bc", "abc"));
	assert(_ft_strjoin_test("ab", "bc", "abbc"));
	assert(_ft_strjoin_test("ab", "bc", "abbc"));
	assert(_ft_strjoin_test("ab", "", "ab"));
	assert(_ft_strjoin_test("", "bc", "bc"));
	assert(_ft_strjoin_test("", "", ""));
}

int	_ft_strjoin_test(char const *s1, char const *s2, char const *to_be)
{
	int		cmp_result;
	char	*join;

	cmp_result = -1;
	join = ft_strjoin(s1, s2);
	if (join != NULL)
	{
		cmp_result = strcmp(join, to_be);
		if (cmp_result != 0)
			printf("join: %s, concat: %s", join, to_be);
	}
	free(join);
	return (cmp_result == 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:38:28 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/11 17:39:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		_ft_split_test(char const *s, char c, char *to_be[]);
char	**free_splitted(char **splitted);

void	ft_split_test(void)
{
	assert(_ft_split_test("1,2,3", ',', (char *[]){"1", "2", "3", NULL}));
	assert(_ft_split_test("1,,2,3", ',', (char *[]){"1", "2", "3", NULL}));
	assert(_ft_split_test(",,1,2", ',', (char *[]){"1", "2", NULL}));
	assert(_ft_split_test("1,2,,", ',', (char *[]){"1", "2", NULL}));
	assert(_ft_split_test("1", ',', (char *[]){"1", NULL}));
	assert(_ft_split_test(",1", ',', (char *[]){"1", NULL}));
	assert(_ft_split_test("1,,", ',', (char *[]){"1", NULL}));
	assert(_ft_split_test("", ',', (char *[]){NULL}));
	assert(_ft_split_test(",", ',', (char *[]){NULL}));
}

int	_ft_split_test(char const *s, char c, char *to_be[])
{
	char	**splitted;
	size_t	index;
	int		test_result;

	splitted = ft_split(s, c);
	if (splitted == NULL)
		return (0);
	index = 0;
	while (splitted[index] != NULL && to_be[index] != NULL)
	{
		if (strcmp(splitted[index], to_be[index]))
		{
			fprintf(stdout, "%s, %s\n", splitted[index], to_be[index]);
			free_splitted(splitted);
			return (0);
		}
		index++;
	}
	if (splitted[index] == NULL && to_be[index] == NULL)
		test_result = !0;
	else
		test_result = 0;
	free_splitted(splitted);
	return (test_result);
}

char	**free_splitted(char **splitted)
{
	size_t	index;

	index = 0;
	while (splitted[index] != NULL)
	{
		free(splitted[index]);
		index++;
	}
	free(splitted);
	return (NULL);
}

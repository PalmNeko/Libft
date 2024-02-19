/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:06:19 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/10 15:41:49 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <assert.h>

int	_ft_strrchr_test(char *src, int search);

void	ft_strrchr_test(void)
{
	assert(_ft_strrchr_test("abcdefg", 'c'));
	assert(_ft_strrchr_test("abcdefg", '\0'));
	assert(_ft_strrchr_test("abcdefg", 'a'));
	assert(_ft_strrchr_test("abcdefg", 'g'));
	assert(_ft_strrchr_test("", 'g'));
	assert(_ft_strrchr_test("", '\0'));
	assert(_ft_strrchr_test("test", 't' + 256));
}

int	_ft_strrchr_test(char *src, int search)
{
	return (ft_strrchr(src, search) == strrchr(src, search));
}

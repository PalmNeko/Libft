/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:17:42 by tookuyam          #+#    #+#             */
/*   Updated: 2023/09/27 15:21:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <string.h>

void	ft_strlen_test(void)
{
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen("a") == strlen("a"));
	assert(ft_strlen("abc") == strlen("abc"));
	return ;
}

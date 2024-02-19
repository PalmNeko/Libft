/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:02:04 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 18:14:39 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	g_iter_check;

static void	del(void *a)
{
	a = NULL;
	g_iter_check += 1;
	return ;
}

void	ft_lstdelone_test(void)
{
	g_iter_check = 0;
	ft_lstdelone(ft_lstnew((void *)1), del);
	assert(g_iter_check == 1);
	return ;
}

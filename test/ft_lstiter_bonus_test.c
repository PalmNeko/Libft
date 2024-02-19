/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:13:27 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 19:42:36 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	g_iter_check;

static void	count_up(void *content)
{
	content = NULL;
	g_iter_check += 1;
	return ;
}

static void	del(void *content)
{
	content = NULL;
	return ;
}

void	ft_lstiter_test(void)
{
	t_list	*root;
	int		count;

	g_iter_check = 0;
	root = NULL;
	count = 0;
	while (count < 17)
	{
		ft_lstadd_front(&root, ft_lstnew((void *)1));
		count++;
	}
	ft_lstiter(root, count_up);
	assert(g_iter_check == 17);
	ft_lstclear(&root, del);
	return ;
}

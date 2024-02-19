/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:08:15 by tookuyam          #+#    #+#             */
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

void	ft_lstclear_test(void)
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
	ft_lstclear(&root, del);
	assert(root == NULL);
	assert(g_iter_check == 17);
	return ;
}

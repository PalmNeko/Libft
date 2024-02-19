/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:47:29 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 19:05:17 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	lst_del(void *a)
{
	a = NULL;
	return ;
}

void	ft_lstlast_test(void)
{
	t_list	*root;
	t_list	*last_lst;
	long	value;

	root = NULL;
	assert(ft_lstlast(root) == NULL);
	value = 1;
	while (value < 4)
	{
		ft_lstadd_back(&root, ft_lstnew((void *)value));
		last_lst = ft_lstlast(root);
		assert(last_lst->next == NULL);
		assert(last_lst->content == (void *)value);
		value ++;
	}
	assert(ft_lstsize(root) == 3);
	ft_lstclear(&root, lst_del);
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:58:31 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 18:55:11 by tookuyam         ###   ########.fr       */
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

void	ft_lstadd_back_test(void)
{
	t_list	*root;
	t_list	*last_lst;
	t_list	*tmp_list;

	root = NULL;
	ft_lstadd_back(&root, ft_lstnew((void *)1));
	assert(root != NULL);
	tmp_list = root;
	ft_lstadd_back(&root, ft_lstnew((void *)2));
	last_lst = ft_lstlast(root);
	assert(last_lst != tmp_list);
	assert(last_lst->content == (void *)2);
	assert(last_lst->next == NULL);
	assert(ft_lstsize(root) == 2);
	ft_lstclear(&root, lst_del);
	return ;
}

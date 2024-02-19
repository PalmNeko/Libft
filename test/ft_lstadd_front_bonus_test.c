/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:26:00 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 18:52:33 by tookuyam         ###   ########.fr       */
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

void	ft_lstadd_front_test(void)
{
	t_list	*root;
	t_list	*tmp_list;

	root = NULL;
	ft_lstadd_front(&root, ft_lstnew((void *)1));
	assert(root != NULL);
	tmp_list = root;
	ft_lstadd_front(&root, ft_lstnew((void *)2));
	assert(root != tmp_list);
	assert(root->content == (void *)2);
	assert(root->next == tmp_list);
	assert(ft_lstsize(root) == 2);
	ft_lstclear(&root, lst_del);
	return ;
}

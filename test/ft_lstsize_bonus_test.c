/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:38:04 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 18:53:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	del_lst(void *a)
{
	a = NULL;
	return ;
}

void	ft_lstsize_test(void)
{
	t_list	*root;

	root = NULL;
	assert(ft_lstsize(root) == 0);
	ft_lstadd_front(&root, ft_lstnew((void *)1));
	assert(ft_lstsize(root) == 1);
	ft_lstadd_front(&root, ft_lstnew((void *)1));
	assert(ft_lstsize(root) == 2);
	ft_lstclear(&root, del_lst);
	return ;
}

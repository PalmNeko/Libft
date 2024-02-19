/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:20:52 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 19:43:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	g_map_check;
static int	g_del_count;

static void	_ft_lstmap_success_test(void);
static void	*count_up(void *content);
static void	del_content(void *content);

void	ft_lstmap_test(void)
{
	_ft_lstmap_success_test();
	return ;
}

static void	_ft_lstmap_success_test(void)
{
	t_list	*root;
	t_list	*map_lst;
	t_list	*tmp;
	int		count;

	root = NULL;
	count = 0;
	while (count < 17)
		ft_lstadd_back(&root, ft_lstnew((void *)(sizeof(void *) * (count++))));
	g_map_check = 0;
	g_del_count = 0;
	map_lst = ft_lstmap(root, count_up, del_content);
	assert(g_map_check == 17);
	tmp = map_lst;
	count = 0;
	while (tmp != NULL && count < 17)
	{
		assert((tmp->content == (void *)(sizeof(void *) * (count++) + 1)));
		tmp = tmp->next;
	}
	assert(g_map_check == 17);
	assert(g_del_count == 0);
	ft_lstclear(&map_lst, del_content);
	ft_lstclear(&root, del_content);
	return ;
}

static void	*count_up(void *content)
{
	g_map_check += 1;
	return (content + 1);
}

static void	del_content(void *content)
{
	content = NULL;
	g_del_count = 0;
	return ;
}

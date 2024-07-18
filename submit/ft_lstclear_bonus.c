/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/18 12:44:01 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_lst;
	t_list	*free_lst;

	if (lst == NULL)
		return ;
	if ((*lst)->prev != NULL)
		(*lst)->prev->next = NULL;
	del_lst = (*lst)->next;
	while (del_lst != NULL)
	{
		free_lst = del_lst;
		del_lst = del_lst->next;
		ft_lstdelone(free_lst, del);
	}
	del_lst = (*lst);
	while (del_lst != NULL)
	{
		free_lst = del_lst;
		del_lst = del_lst->prev;
		ft_lstdelone(free_lst, del);
	}
	*lst = NULL;
	return ;
}

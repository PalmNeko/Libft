/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:51 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 16:23:44 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_lst;
	t_list	*free_lst;

	del_lst = (*lst);
	while (del_lst != NULL)
	{
		del(del_lst->content);
		free_lst = del_lst;
		del_lst = del_lst->next;
		free(free_lst);
	}
	*lst = NULL;
	return ;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:51:07 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 17:01:50 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map_lst;
	t_list	*lst_root_ptr;
	t_list	*target_lst;

	map_lst = NULL;
	lst_root_ptr = NULL;
	while (lst != NULL)
	{
		target_lst = ft_lstnew(f(lst->content));
		if (target_lst == NULL)
		{
			ft_lstclear(&lst_root_ptr, del);
			return (NULL);
		}
		if (lst_root_ptr == NULL)
			lst_root_ptr = target_lst;
		ft_lstadd_back(&map_lst, target_lst);
		map_lst = target_lst;
		lst = lst->next;
	}
	return (lst_root_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:12:42 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/12 15:16:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_list;

	last_list = ft_lstlast(*lst);
	if (last_list == NULL)
		*lst = new;
	else
	{
		if (last_list->next != NULL)
		{
			last_list->next->prev = new;
			new->next = last_list->next;
		}
		last_list->next = new;
		new->prev = last_list;
	}
	return ;
}

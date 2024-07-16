/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:02:06 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/16 15:30:09 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*itr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if ((*lst)->next != NULL)
		(*lst)->next->prev = NULL;
	itr = *lst;
	while (itr->prev != NULL)
		itr = itr->prev;
	if ((*lst)->next != NULL)
		(*lst)->next->prev = (*lst);
	new->next = itr;
	new->prev = itr->prev;
	itr->prev = new;
	if (itr == *lst)
		*lst = new;
	return ;
}

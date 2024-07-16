/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:04:51 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/16 15:37:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp_prev;
	t_list	*itr;

	if (lst == NULL)
		return (0);
	tmp_prev = lst->prev;
	if (tmp_prev != NULL)
		tmp_prev->next = NULL;
	size = 0;
	itr = lst;
	while (itr != NULL)
	{
		itr = itr->next;
		size++;
	}
	if (tmp_prev != NULL)
		tmp_prev->next = lst;
	return (size);
}

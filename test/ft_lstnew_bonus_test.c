/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:06:37 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/09 17:11:15 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_lstnew_test(void)
{
	t_list	*lst;

	lst = ft_lstnew((void *)1);
	assert(lst->next == NULL);
	assert(lst->content == (void *)1);
	free(lst);
	return ;
}

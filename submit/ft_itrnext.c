/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itrnext.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:07:32 by tookuyam          #+#    #+#             */
/*   Updated: 2024/08/03 17:07:32 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_itrnext(t_iter *itr)
{
	void	*result;

	result = NULL;
	if (itr->has_next(itr))
	{
		result = itr->next(itr);
		itr->index += 1;
	}
	return (result);
}

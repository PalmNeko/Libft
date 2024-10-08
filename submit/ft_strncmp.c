/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:44:40 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/20 15:24:57 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (s1[count] == '\0' && s2[count] == '\0')
			return (0);
		else if (s1[count] != s2[count])
			return (((unsigned char)s1[count] - (unsigned char)s2[count]));
		count++;
	}
	return (0);
}

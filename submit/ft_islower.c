/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:11:02 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/07 19:21:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islower(int c)
{
	unsigned char	uc;

	uc = c;
	if ('a' <= uc && uc <= 'z')
		return (!0);
	else
		return (0);
}

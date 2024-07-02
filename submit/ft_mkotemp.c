/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkotemp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:20:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/02 16:45:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include "libft.h"

int	ft_mkostemp(char *template)
{
	size_t		len;
	char		*rep_start;
	int			index;
	int			fd;

	len = ft_strlen(template);
	if (len < 6 || ft_strmatch("XXXXXX$", template))
	{
		errno = EINVAL;
		return (-1);
	}
	rep_start = &template[len - 6];
	index = 0;
	while (index < 10)
	{
		errno = 0;
		ft_replace_random_alpha(
			rep_start, 6, ft_addr2uint32_t(template), 6 * index);
		fd = open(template, O_RDWR | O_CREAT | O_EXCL, S_IWUSR | S_IRUSR);
		if (fd != -1 || (fd == -1 && errno != EEXIST))
			return (fd);
		index++;
	}
	errno = EEXIST;
	return (-1);
}

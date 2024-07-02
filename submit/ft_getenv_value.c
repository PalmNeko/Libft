/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:57:23 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/02 18:59:22 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 * @brief get value in memory from environ.environ(7)
 * @param key keyvalue
 */
char	*ft_getenv_value(char *key)
{
	extern char	**environ;
	size_t		index;
	size_t		iter;

	index = 0;
	while (environ[index] != NULL)
	{
		if (ft_strncmp(key, environ[index], ft_strlen(key)) == 0)
			break ;
		index++;
	}
	if (environ[index] == NULL)
		return (NULL);
	iter = 0;
	while (environ[index][iter] != '=' && environ[index][iter] != '\0')
		iter++;
	if (environ[index][iter] == '\0')
		return (NULL);
	return (ft_strdup(environ[index] + iter + 1));
}

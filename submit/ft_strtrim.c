/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:21:53 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/16 18:01:11 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

static int	is_includes(char c, char const *set);
static char	*strskip(char const *s1, char const *set);
static char	*strrskip(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	char	*start;
	char	*end;
	size_t	size;

	start = strskip(s1, set);
	end = strrskip(start, set);
	size = (end - start) + 1;
	trim = (char *)malloc(sizeof(char) * size);
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, start, size);
	return (trim);
}

static char	*strskip(char const *s1, char const *set)
{
	while (is_includes(*s1, set))
		s1++;
	return ((char *)s1);
}

static char	*strrskip(char const *s1, char const *set)
{
	size_t	len;

	len = ft_strlen(s1);
	while (len >= 1 && is_includes(s1[len - 1], set))
		len--;
	return ((char *)(s1 + len));
}

static int	is_includes(char c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (!0);
		set++;
	}
	return (0);
}

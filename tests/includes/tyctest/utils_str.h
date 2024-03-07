/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:10:01 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:13:00 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STR_H
# define UTILS_STR_H

#include <stddef.h>

char	*trimchr(char *str, char trim);
int		stricmp(const char *string1, const char *string2);
int		is_raw_number(char *str);

#ifdef WINDOWS

char *strndup(char *str, size_t len);

#endif

char	*lltoa(long long value, char *buffer, int base);
char	*ulltoa(unsigned long long value, char *buffer, int base);

#endif

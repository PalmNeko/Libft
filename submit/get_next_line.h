/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:09:06 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/04 12:41:07 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
char		*_get_next_line(char **str, int fd, char **leftovers);
char		*ft_strjoin_fd(char *left, int fd, int *is_eof);
char		*ft_substrchr(char const *str, char sep);

size_t		ft_strlenchr(char const *s, char find);
void		*free_manager(char **str);
char		*ft_strchr(const char *s, char find);
char		*read_str(int fd);

#endif
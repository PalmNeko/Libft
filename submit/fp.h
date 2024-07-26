/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:01:34 by tookuyam          #+#    #+#             */
/*   Updated: 2024/07/23 12:15:25 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_H
# define FP_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_vdprintf(int fd, const char *format, va_list arg_ptr);

#endif

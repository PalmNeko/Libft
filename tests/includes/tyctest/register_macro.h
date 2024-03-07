/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_macro.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:35:33 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 16:12:38 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTER_MACRO_H
# define REGISTER_MACRO_H

#include "register_functions.h"

/**
 * register test function
 * @param TITLE raw string(not char *)
 * @param SECTION raw string(not char)
 */
# define REGISTER_TEST(TITLE, SECTION) \
	__attribute__((constructor)) \
	static void register_ ## TITLE ## SECTION (void) { \
		register_func( TITLE ## SECTION, #TITLE, #SECTION ); \
	}

#endif
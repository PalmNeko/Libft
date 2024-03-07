/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner_adapter.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:32:14 by tookuyam          #+#    #+#             */
/*   Updated: 2024/03/05 18:32:14 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RUNNER_ADAPTER_H
# define TEST_RUNNER_ADAPTER_H

# include <stdbool.h>

void	set_failure(void);
void	reset_failure(void);
bool	is_failure(void);

#endif
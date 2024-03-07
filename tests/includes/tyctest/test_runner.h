/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:06:57 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 19:13:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RUNNER_H
# define TEST_RUNNER_H

# include "register_functions.h"

int		run_test_groups(t_test_group g_test_groups[], int g_func_cnt);
int		run_group_tests(t_test_group *group, t_failure_tests_info *failure_info);
int		run_test(t_test_info *test_info, t_failure_tests_info *failure_info);
void	run_test_with_str(char *group_name, char *section);

#endif
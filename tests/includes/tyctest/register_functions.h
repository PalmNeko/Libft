/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_functions.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 22:24:18 by tookuyam          #+#    #+#             */
/*   Updated: 2023/10/31 17:58:13 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REGISTER_FUNCTIONS_H
# define REGISTER_FUNCTIONS_H

# define MAX_TEST_FUNCTIONS (1024)
# define MAX_CHILD_TESTS (256)
# define MAX_FAILURE_TESTS (8192)

typedef void(*t_test_function)(void);

typedef struct s_test_info {
	t_test_function	test_function;
	char			*title;
	char			*section;
	int				is_success;
}	t_test_info;

typedef struct s_test_functions {
	t_test_info	child_tests[MAX_CHILD_TESTS];
	int			stored_cnt;
	char		*title;
}	t_test_group;

typedef struct s_failure_tests_info {
	t_test_info	*failure_tests[MAX_FAILURE_TESTS];
	int			stored_cnt;
	int			over_flag;
}	t_failure_tests_info;

void			register_func(t_test_function test_function, char *title, char *section);
void			call_function(char *title, char *section);
int				run_all_group_tests(void);
t_test_group	*get_test_groups(void);
int				get_test_groups_cnt(void);

#endif
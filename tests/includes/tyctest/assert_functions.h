/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:36:46 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:21:21 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_FUNCTIONS_H
# define ASSERT_FUNCTIONS_H

# include "header.h"
# include "comparison.h"

/**
 * test that condition is equal to true.
 * @throw
 * @param condition condition
 */
# define ASSERT_TRUE(condition) do { \
	TEST_BOOL(true, condition, "==", NUM_EQ, "assert_true", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0);

/**
 * test that condition is equal to false.
 * @throw
 * @param condition condition
 */
# define ASSERT_FALSE(condition) do { \
	TEST_BOOL(false, condition, "==", NUM_EQ, "assert_false", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0);

/**
 * test that expected is equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_EQ(expected, actual) do { \
	TEST_NUMBER(expected, actual, "==", NUM_EQ, "assert_eq", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0);

/**
 * test that expected is not equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_NE(expected, actual) do {\
	TEST_NUMBER(expected, actual, "!=", NUM_NE, "assert_ne", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is less than actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_LT(expected, actual) do {\
	TEST_NUMBER(expected, actual, "<", NUM_LT, "assert_lt", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is less than or equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_LE(expected, actual) do {\
	TEST_NUMBER(expected, actual, "<=", NUM_LE, "assert_le", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is greater than to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_GT(expected, actual) do {\
	TEST_NUMBER(expected, actual, ">", NUM_GT, "assert_gt", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is greater than or equal to actual.
 * @throw
 * @param expected actual
 */
# define ASSERT_GE(expected, actual) do {\
	TEST_NUMBER(expected, actual, ">=", NUM_GE, "assert_ge", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is equal to actual.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STREQ(expected, actual) do { \
	TEST_STRING(expected, actual, "==", STR_EQ, "assert_streq", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is not equal to actual.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRNE(expected, actual) do { \
	TEST_STRING(expected, actual, "!=", STR_NE, "assert_strne", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is equal to actual. ignore character case.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRCASEEQ(expected, actual) do { \
	TEST_STRING(expected, actual, "==", STR_CASEEQ, "assert_strcaseeq", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

/**
 * test that expected is not equal to actual. ignore character case.
 * @throw
 * @param expected expected value
 * @param actual actual value
 */
# define ASSERT_STRCASENE(expected, actual)  do { \
	TEST_STRING(expected, actual, "!=", STR_CASENE, "assert_strcaseeq", "\033[31mAbort\033[m"); \
	if (is_failure()) return ; \
} while (0)

#endif
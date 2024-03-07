/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expect_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:42:35 by tookuyam          #+#    #+#             */
/*   Updated: 2023/11/01 13:17:26 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPECT_FUNCTIONS_H
# define EXPECT_FUNCTIONS_H

# include <string.h>
# include "utils_str.h"

# define __ERROR_MESSAGE "\033[33mError\033[m"

/**
 * test that condition is equal to true.
 * @param condition condition
 */
# define EXPECT_TRUE(condition) do { \
	TEST_BOOL(true, condition, "==", NUM_EQ, "assert_true", __ERROR_MESSAGE); \
} while (0);


/**
 * test that condition is equal to true.
 * @param condition condition
 */
# define EXPECT_FALSE(condition) do { \
	TEST_BOOL(false, condition, "==", NUM_EQ, "assert_false", __ERROR_MESSAGE); \
} while (0);

/**
 * test that expected is equal to actual.
 * @param expected actual
 */
# define EXPECT_EQ(expected, actual) do { \
	TEST_NUMBER(expected, actual, "==", NUM_EQ, "assert_eq", __ERROR_MESSAGE); \
} while (0);

/**
 * test that expected is not equal to actual.
 * @param expected actual
 */
# define EXPECT_NE(expected, actual) do {\
	TEST_NUMBER(expected, actual, "!=", NUM_NE, "assert_ne", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is less than actual.
 * @param expected actual
 */
# define EXPECT_LT(expected, actual) do {\
	TEST_NUMBER(expected, actual, "<", NUM_LT, "assert_lt", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is less than or equal to actual.
 * @param expected actual
 */
# define EXPECT_LE(expected, actual) do {\
	TEST_NUMBER(expected, actual, "<=", NUM_LE, "assert_le", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is greater than to actual.
 * @param expected actual
 */
# define EXPECT_GT(expected, actual) do {\
	TEST_NUMBER(expected, actual, ">", NUM_GT, "assert_gt", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is greater than or equal to actual.
 * @param expected actual
 */
# define EXPECT_GE(expected, actual) do {\
	TEST_NUMBER(expected, actual, ">=", NUM_GE, "assert_ge", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is equal to actual.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STREQ(expected, actual) do { \
	TEST_STRING(expected, actual, "==", STR_EQ, "assert_streq", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is not equal to actual.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STRNE(expected, actual) do { \
	TEST_STRING(expected, actual, "!=", STR_NE, "assert_strne", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is equal to actual. ignore character case.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STRCASEEQ(expected, actual) do { \
	TEST_STRING(expected, actual, "==", STR_CASEEQ, "assert_strcaseeq", __ERROR_MESSAGE); \
} while (0)

/**
 * test that expected is not equal to actual. ignore character case.
 * @param expected expected value
 * @param actual actual value
 */
# define EXPECT_STRCASENE(expected, actual) do { \
	TEST_STRING(expected, actual, "!=", STR_CASENE, "assert_strcaseeq", __ERROR_MESSAGE); \
} while (0)

#endif

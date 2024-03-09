
#ifndef HEADER_H
# define HEADER_H

# include <stdbool.h>
# include "test_runner_adapter.h"

/**
 * print as functions
 */
void print_as_short(void *value);
void print_as_int(void *value);
void print_as_long(void *value);
void print_as_long_long(void *value);
void print_as_unsigned_int(void *value);
void print_as_unsigned_long(void *value);
void print_as_unsigned_long_long(void *value);
void print_as_float(void *value);
void print_as_double(void *value);
void print_as_char(void *value);
void print_as_char_pointer(void *value);
void print_as_const_char_pointer(void *value);
void print_as_void_pointer(void *value);

/**
 * assigners
 */
void	*assign_bool(void **variable, bool value);
void	*assign_short(void **variable, short value);
void	*assign_int(void **variable, int value);
void	*assign_long(void **variable, long value);
void	*assign_long_long(void **variable, long long value);
void	*assign_unsigned_int(void **variable, unsigned int value);
void	*assign_unsigned_long(void **variable, unsigned long value);
void	*assign_unsigned_long_long(void **variable, unsigned long long value);
void	*assign_float(void **variable, float value);
void	*assign_double(void **variable, double value);
void	*assign_char(void **variable, char value);
void	*assign_char_pointer(void **variable, char *value);
void	*assign_const_char_pointer(void **variable, const char *value);
void	*assign_void_pointer(void **variable, void *value);

#define ASSIGN(VAL) _Generic((VAL), \
	bool: assign_bool, \
	short: assign_short, \
	int: assign_int, \
	long: assign_long, \
	long long: assign_long_long, \
	unsigned int: assign_unsigned_int, \
	unsigned long: assign_unsigned_long, \
	unsigned long long: assign_unsigned_long_long, \
	float: assign_float, \
	double: assign_double, \
	char: assign_char, \
	char *: assign_char_pointer, \
	const char *: assign_const_char_pointer, \
	default: assign_void_pointer \
)

#define GET_TYPE(VAR) _Generic((VAR), \
	bool: "bool", \
	short: "short", \
	int: "int", \
	long: "long", \
	long long: "long long", \
	unsigned int: "unsigned int", \
	unsigned long: "unsigned long", \
	unsigned long long: "unsigned long long", \
	float: "float", \
	double: "double", \
	char: "char", \
	char *: "char *", \
	const char *: "const char *", \
	default: "void *" \
)

/**
 * get value
 */
#define GET_VAL(VAR_VOID_PTR, TYPED_VAR) _Generic((TYPED_VAR), \
	bool: *(bool *)VAR_VOID_PTR, \
	short: *(short *)VAR_VOID_PTR, \
	int: *(int *)VAR_VOID_PTR, \
	long: *(long *)VAR_VOID_PTR, \
	long long: *(long long *)VAR_VOID_PTR, \
	unsigned int: *(unsigned int *)VAR_VOID_PTR, \
	unsigned long: *(unsigned long *)VAR_VOID_PTR, \
	unsigned long long: *(unsigned long long *)VAR_VOID_PTR, \
	float: *(float *)VAR_VOID_PTR, \
	double: *(double *)VAR_VOID_PTR, \
	char: *(char *)VAR_VOID_PTR, \
	char *: (char *)VAR_VOID_PTR, \
	const char *: (const char *)VAR_VOID_PTR, \
	default: VAR_VOID_PTR \
)

/**
 *
*/
typedef struct {
	char	*raw;
	void	*value_ptr;
	char	*type;
	char	*print_type; //bool number string
} t_macro_argument_info;

/**
 * log print
 */
typedef struct {
	char	*test_function_name;
	char	*caption;
	t_macro_argument_info	expect_info;
	t_macro_argument_info	actual_info;
	char	*ope;
	int		line;
	char*	filename;
} t_log_info;

void log_print(t_log_info *);

#define TEST_NUMBER(expect, actual, operator, condition_macro, test_name_str, msg_str) do { \
	void *expect_val = NULL; \
	void *actual_val = NULL; \
	char *expect_type = GET_TYPE(expect); \
	char *actual_type = GET_TYPE(actual); \
	ASSIGN(expect)(&expect_val, expect); \
	ASSIGN(actual)(&actual_val, actual); \
	if (!(condition_macro(GET_VAL(expect_val, expect), GET_VAL(actual_val, actual)))) \
	{ \
		log_print(&(t_log_info) { \
			.test_function_name = test_name_str, \
			.caption = msg_str, \
			.expect_info = (t_macro_argument_info) { \
				.raw = #expect, \
				.value_ptr = expect_val, \
				.type = expect_type, \
				.print_type = "number"},\
			.actual_info = (t_macro_argument_info) { \
				.raw = #actual, \
				.value_ptr = actual_val, \
				.type = actual_type, \
				.print_type = "number"},\
			.ope = operator, \
			.line = __LINE__, \
			.filename = __FILE__, \
		}); \
		set_failure(); \
	} \
	\
} while(0)

#define TEST_BOOL(expect, actual, operator, condition_macro, test_name_str, msg_str) do { \
	void *expect_val = NULL; \
	void *actual_val = NULL; \
	char *expect_type = GET_TYPE(expect); \
	char *actual_type = GET_TYPE(actual); \
	ASSIGN(expect)(&expect_val, expect); \
	ASSIGN(actual)(&actual_val, actual); \
	if (!(condition_macro(GET_VAL(expect_val, expect), GET_VAL(actual_val, actual)))) \
	{ \
		log_print(&(t_log_info) { \
			.test_function_name = test_name_str, \
			.caption = msg_str, \
			.expect_info = (t_macro_argument_info) { \
				.raw = #expect, \
				.value_ptr = expect_val, \
				.type = expect_type, \
				.print_type = "bool"},\
			.actual_info = (t_macro_argument_info) { \
				.raw = #actual, \
				.value_ptr = actual_val, \
				.type = actual_type, \
				.print_type = "bool"},\
			.ope = operator, \
			.line = __LINE__, \
			.filename = __FILE__, \
		}); \
		set_failure(); \
	} \
	\
} while(0)

#define TEST_STRING(expect, actual, operator, condition_macro, test_name_str, msg_str) do { \
	void *expect_val = NULL; \
	void *actual_val = NULL; \
	char *expect_type = GET_TYPE(expect); \
	char *actual_type = GET_TYPE(actual); \
	ASSIGN(expect)(&expect_val, expect); \
	ASSIGN(actual)(&actual_val, actual); \
	if (!(condition_macro(GET_VAL(expect_val, expect), GET_VAL(actual_val, actual)))) \
	{ \
		log_print(&(t_log_info) { \
			.test_function_name = test_name_str, \
			.caption = msg_str, \
			.expect_info = (t_macro_argument_info) { \
				.raw = #expect, \
				.value_ptr = expect_val, \
				.type = expect_type, \
				.print_type = "string"},\
			.actual_info = (t_macro_argument_info) { \
				.raw = #actual, \
				.value_ptr = actual_val, \
				.type = actual_type, \
				.print_type = "string"},\
			.ope = operator, \
			.line = __LINE__, \
			.filename = __FILE__, \
		}); \
		set_failure(); \
	} \
	\
} while(0)

#endif
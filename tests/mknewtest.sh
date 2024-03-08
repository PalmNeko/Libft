#!bin/bash

cd $(dirname $0)

if [[ -z "$1" ]] then
	echo 'require new test name ex: ft_atoi.c -> ft_atoi'
	exit 1;
fi

if [[ ! -f "../submit/$1.c" ]] then
	echo "no such file: ../submit/$1.c"
	exit 1;
fi

echo "
#include \"tyctest.h\"
#include \"libft.h\"
#include <limits.h>
#include <errno.h>

TEST($1, basic_usage) {
	EXPECT_STRNE(\"actual\", \"expected\");
}
" > "src/$1_test.c"

code "src/$1_test.c"
code "../submit/$1.c"

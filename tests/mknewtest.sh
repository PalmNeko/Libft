#!bin/bash

cd $(dirname $0)

first_file=$(bash ../scripts/check-have-testfiles.sh | tr ' ' '\n' | head --lines=1)
create_target=$(basename "${first_file%.c}")
if [[ -z "$create_target" ]] then
	echo 'require new test name ex: ft_atoi.c -> ft_atoi'
	exit 1;
fi

printf "Are you sure creating? target: $create_target (y/n) "
read YN
if [[ "$YN" != "y" ]] then
	echo 'aborting.'
	exit 1
fi

if [[ ! -f "../submit/$create_target.c" ]] then
	echo "no such file: ../submit/$create_target.c"
	exit 1;
fi

echo "
#include \"tyctest.h\"
#include \"libft.h\"
#include <limits.h>
#include <errno.h>

TEST($create_target, basic_usage) {
	EXPECT_STRNE(\"actual\", \"expected\");
}
" > "src/${create_target}_test.c"

code "src/${create_target}_test.c"
code "../submit/${create_target}.c"

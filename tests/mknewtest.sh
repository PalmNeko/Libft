#!bin/bash

cd $(dirname $0)

first_file=$(bash ../scripts/check-have-testfiles.sh | tr ' ' '\n' | head -n 1)
create_target=$(basename "${first_file%.c}")
if test -z "$create_target" && true; then
	echo 'createed all test'
	exit 1;
fi

printf "Are you sure creating? target: $create_target (y/n) "
read YN
if test "$YN" != "y"; then
	echo 'aborting.'
	exit 1
fi

if test ! -f "../submit/$create_target.c"; then
	echo "no such file: ../submit/$create_target.c"
	exit 1;
fi

echo "
#include \"tyctest.h\"
#include \"libft.h\"
#include <limits.h>
#include <errno.h>

TEST($create_target, basic_usage) {
	EXPECT_STRNE(\"expected\", \"actual\");
}
" > "src/${create_target}_test.c"

echo
echo "target:    ../submit/${create_target}.c"
echo "generated: src/${create_target}_test.c"
echo

# Check have test files

cd $(dirname $0)
cd ..

SUBMIT_FILES="$(find ./submit -name "*.c")"
TEST_FILES=$(find ./tests -name "*_test.c")

for filename in $TEST_FILES; do
	filename="${filename%_test.c}.c"
	filename=$(basename $filename)
	SUBMIT_FILES=$(echo $SUBMIT_FILES | tr ' ' '\n' | grep -v "${filename%.c}.c\$")
done

echo $SUBMIT_FILES | tr ' ' '\n'

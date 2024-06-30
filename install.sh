#!/bin/bash

set -e

DIR_NAME=libft
test -d "$DIR_NAME" && (echo 'you have to delete '"$DIR_NAME"' directory' ; exit 1)
git clone --progress --depth 1 git@github.com:PalmNeko/Libft.git "$DIR_NAME"
cd "$DIR_NAME" && make

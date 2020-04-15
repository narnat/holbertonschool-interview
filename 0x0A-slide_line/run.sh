#!/usr/bin/env bash

gcc -Wall -Wextra -Werror -pedantic -o 0-slide_line 0-main.c 0-slide_line.c || exit 1

./0-slide_line L 2 2 0 0
echo "******************************"

./0-slide_line L 2 2 0 0 0 0 0 2 0 0 0 2 0 4
echo "******************************"

./0-slide_line R 2 2 2 2
echo "******************************"

./0-slide_line R 2 2 2 2 2
echo "******************************"

./0-slide_line L 2 4 8 16
echo "******************************"

./0-slide_line R 2 4 8 16
echo "******************************"

./0-slide_line R 4 4 8 16
echo "******************************"

#!/bin/bash
files=( *.c )
gcc -c -Wall -Werror -Wextra -pedantic "${files[@]}"
ar -rc liball.a "${files[@]/%.c/.o}"
rm "${files[@]/%.c/.o}"

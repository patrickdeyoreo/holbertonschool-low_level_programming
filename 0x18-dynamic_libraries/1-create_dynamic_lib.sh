#!/bin/bash
gcc -fPIC -Wall -Werror -Wextra -pedantic -c *.c
gcc -shared -o liball.so *.o
rm -- *.o

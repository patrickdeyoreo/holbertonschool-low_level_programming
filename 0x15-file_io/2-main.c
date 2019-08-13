#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    int res;

    if (ac != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = append_text_to_file(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
julien@ubuntu:~/0x15. File descriptors and permissions$ echo -n Hello > hello
julien@ubuntu:~/0x15. File descriptors and permissions$ ls -l hello
-rw-rw-r-- 1 julien julien 5 Dec  3 14:48 hello
julien@ubuntu:~/0x15. File descriptors and permissions$ gcc -Wall -pedantic -Werror -Wextra 2-main.c 2-append_text_to_file.c -o c
julien@ubuntu:~/0x15. File descriptors and permissions$ ./c hello " World!
> "
-> 1)
julien@ubuntu:~/0x15. File descriptors and permissions$ cat hello 
Hello World!
julien@ubuntu:~/0x15. File descriptors and permissions$

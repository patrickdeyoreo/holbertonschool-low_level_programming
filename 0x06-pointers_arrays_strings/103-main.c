#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[] = "this is a string!\0and this is the rest of the #buffer :)\1\2\3\4\5\6\7#cisfun\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x21\x34\x56#pointersarefun #infernumisfun\n";
    char buffer2[] = "Aa1Bb2Cc3";
    char buffer3[] = "";

    printf("\n%s\n", buffer);
    printf("---------------------------------\n");
    print_buffer(buffer, sizeof(buffer));

    printf("\n%s\n", buffer);
    printf("---------------------------------\n");
    print_buffer(buffer, 10);

    printf("\n%s\n", buffer);
    printf("---------------------------------\n");
    print_buffer(buffer, 0);

    printf("\n%s\n", buffer2);
    printf("---------------------------------\n");
    print_buffer(buffer2, sizeof(buffer2));

    printf("\n%s\n", buffer2);
    printf("---------------------------------\n");
    print_buffer(buffer2, 0);

    printf("\n%s\n", buffer3);
    printf("---------------------------------\n");
    print_buffer(buffer3, sizeof(buffer3));

    printf("\n%s\n", buffer3);
    printf("---------------------------------\n");
    print_buffer(buffer3, 0);

    return (0);
}

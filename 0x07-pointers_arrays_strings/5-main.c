#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    puts("Checking s=\"hello, world\", f=\"world\"");
    t = _strstr(s, f);
    if (t)
	    printf("%s\n", t);
    else
	    puts("NULL");

    s = "hello, world!";
    f = "world";
    puts("Checking s=\"hello, world!\", f=\"world\"");
    t = _strstr(s, f);
    if (t)
	    printf("%s\n", t);
    else
	    puts("NULL");

    s = "";
    f = "";
    puts("Checking s=\"\", f=\"\"");
    t = _strstr(s, f);
    if (t)
	    printf("%s\n", t);
    else
	    puts("NULL");

    s = "hello";
    f = "";
    puts("Checking s=\"hello\", f=\"\"");
    t = _strstr(s, f);
    if (t)
	    printf("%s\n", t);
    else
	    puts("NULL");

    s = "";
    f = "world";
    puts("Checking s=\"\", f=\"world\"");
    t = _strstr(s, f);
    if (t)
	    printf("%s\n", t);
    else
	    puts("NULL");

    s = "dats wassup";
    f = "wa";
    puts("Checking s=\"dats wassup\", f=\"wa\"");
    t = _strstr(s, f);
    if (t)
	    printf("%s\n", t);
    else
	    puts("NULL");


    return (0);
}

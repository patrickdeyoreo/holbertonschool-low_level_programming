#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    int s, r;

    s = 1;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = 1024;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = 16;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = 17;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = 25;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = -1;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = 113;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    s = 7919;
    r = is_prime_number(s);
    printf("%d: %d\n", s, r);
    return (0);
}

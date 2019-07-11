#include "holberton.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str, *pat;
    int r;

    str = "main.c";
    pat = "*.c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "m*a*i*n*.*c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "yo-main.c";
    pat = "m*a*i*n*.*c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "m*a*i*n*.*c*";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "main.c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "main*.c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "m*c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "m*c*";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "ma********************************c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "ma********************************c*";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "*";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "***";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "m.*c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main.c";
    pat = "**.*c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main-main.c";
    pat = "ma*in.c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main-main.c";
    pat = "ma*in.*c";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "main";
    pat = "main*d";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    str = "abc";
    pat = "*b";
    r = wildcmp(str, pat);
    printf("string : %s\npattern: %s\nmatched: %d\n", str, pat, r);
    return (0);
}

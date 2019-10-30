#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int arraya[] = {INT_MAX, 1, 2, INT_MIN};
	int arrayb[] = {1};
	int arrayc[] = {2, 1};
	int arrayd[] = {1, 2, 2, 1, 1};

	size_t n =  sizeof(array) / sizeof(array[0]);
	size_t na = sizeof(arraya) / sizeof(arraya[0]);
	size_t nb = sizeof(arrayb) / sizeof(arrayb[0]);
	size_t nc = sizeof(arrayc) / sizeof(arrayc[0]);
	size_t nd = sizeof(arrayd) / sizeof(arrayd[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	puts("\n#-#-#-#-#-#-#-#\n");
	print_array(arraya, na);
	printf("\n");
	quick_sort(arraya, na);
	printf("\n");
	print_array(arraya, na);
	puts("\n#-#-#-#-#-#-#-#\n");
	print_array(arrayb, nb);
	printf("\n");
	quick_sort(arrayb, nb);
	printf("\n");
	print_array(arrayb, nb);
	puts("\n#-#-#-#-#-#-#-#\n");
	print_array(arrayc, nc);
	printf("\n");
	quick_sort(arrayc, nc);
	printf("\n");
	print_array(arrayc, nc);
	puts("\n#-#-#-#-#-#-#-#\n");
	print_array(arrayd, nd);
	printf("\n");
	quick_sort(arrayd, nd);
	printf("\n");
	print_array(arrayd, nd);

	return (0);
}

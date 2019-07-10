#include "holberton.h"

/**
 * print_chessboard - print the chessboard
 * @a: pointer to an the chess board represented as an 8x8 array
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int row, col;

	for (row = 0; row < 8; ++row)
	{
		for (col = 0; col < 8; ++col)
			_putchar(a[row][col]);
		_putchar('\n');
	}
}

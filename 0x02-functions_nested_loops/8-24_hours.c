#include "holberton.h"

/**
 * 24_hours - None
 *
 * Description: None
 * Return: void
 */

void jack_bauer(void)
{
	int m;
	int h;
	for (h = 0; h < 24; ++h)
	{
		for (m = 0; m < 60; ++m)
		{
			_putchar('0' + h / 10);
			_putchar('0' + h % 10);
			_putchar(':');
			_putchar('0' + m / 10);
			_putchar('0' + m % 10);
			_putchar('\n');
		}
	}

}

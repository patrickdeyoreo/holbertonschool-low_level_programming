#include "3-calc.h"
#include <string.h>

/**
 * get_op_func - select the correct function to perform an operation
 * @s: the operation to perform
 *
 * Return: If s is not one of the defined operators ('+', '-', '*', '/', '%'),
 * return NULL. Otherwise, return a pointer to the appropriate function.
 */
int (*get_op_func(char *s))(int, int)
{
	int i = 0;
	op_t ops[] = {
		{ "+", op_add },
		{ "-", op_sub },
		{ "*", op_mul },
		{ "/", op_div },
		{ "%", op_mod },
		{ NULL, NULL }
	};

	while (s && ops[i].op != NULL)
	{
		if (!strcmp(s, ops[i].op))
			return (ops[i].f);
		++i;
	}

	return (NULL);
}

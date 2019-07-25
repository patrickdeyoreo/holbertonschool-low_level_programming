#include "3-calc.h"

/**
 * op_add - add
 * @a: first operand
 * @b: second operand
 * Return: the result of the operation
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtract
 * @a: first operand
 * @b: second operand
 * Return: the result of the operation
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply
 * @a: first operand
 * @b: second operand
 * Return: the result of the operation
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - divide
 * @a: first operand
 * @b: second operand
 * Return: the result of the operation
 */
int op_div(int a, int b)
{
	if (!b)
	{
		puts("Error");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - modulo
 * @a: first operand
 * @b: second operand
 * Return: the result of the operation
 */
int op_mod(int a, int b)
{
	if (!b)
	{
		puts("Error");
		exit(100);
	}
	return (a % b);
}

#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int j, count = 0;
	unsigned long int existing;

	for (j = 63; j >= 0; j--)
	{
		existing = n >> j;

		if (existing & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}

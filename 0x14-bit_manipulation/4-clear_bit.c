#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 * @n: pointer to the number to change
 * @index: index of the bit to set
 * Return: 1 on success, -1 on failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

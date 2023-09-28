#include "main.h"

/**
 * flip_bits - counts the number of bits to flip
 * to get from one number to another
 * @n: first no.
 * @m: second no.
 * Return: count of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int j, count = 0;
	unsigned long int existing;
	unsigned long int x = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		existing = x >> j;
		if (existing & 1)
			count++;
	}

	return (count);
}

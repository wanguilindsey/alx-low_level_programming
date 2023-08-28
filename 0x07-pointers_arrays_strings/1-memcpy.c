#include "main.h"
/**
 * _memcpy - copies memory area
 * @dest: mamory where is stored
 * @src: memory were is copied
 * @n: no of bytes
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int i = n;

	for (; r < i; n++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}

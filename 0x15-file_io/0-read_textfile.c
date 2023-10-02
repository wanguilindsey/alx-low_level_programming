#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Reads text file and prints to STDOUT
 * @filename: text file being
 * @letters: number of letters
 * Return: w- actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
		char *str;
		ssize_t x;
		ssize_t y;
		ssize_t z;

		x = open(filename, O_RDONLY);
		if (x == -1)
			return (0);
		str = malloc(sizeof(char) * letters);
		z = read(x, str, letters);
		y = write(STDOUT_FILENO, str, z);

		free(str);
		close(x);
		return (y);
}

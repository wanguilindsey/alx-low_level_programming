#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buf(char *file);
void off_file(int x);

/**
 * create_buf - assigns 1024 bytes for a buffer
 * @file: name of file
 * Return: A pointer to the newly-allocated buffer
 */
char *create_buf(char *file)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (buf);
}

/**
 * off_file - Closes file descriptors
 * @x: The file descriptor to be closed
 */
void off_file(int x)
{
	int d;

	d = close(x);
	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", x);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 * Return: 0 on success
 * Description: If the argument count is incorrect - exit code 97
 * If file_from does not exist or cannot be read - exit code 98
 * If file_to cannot be created or written to - exit code 99
 * If file_to or file_from cannot be closed - exit code 100
 */
int main(int argc, char *argv[])
{
	int from, to, s, y;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = create_buf(argv[2]);
	from = open(argv[1], O_RDONLY);
	s = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || s == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		y = write(to, buf, s);
		if (to == -1 || y == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		s = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (s > 0);
	free(buf);
	off_file(from);
	off_file(to);

	return (0);
}

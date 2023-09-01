#include <stdio.h>
#include "main.h"

/**
 * main - prints its name
 * @argc: argument count
 * @argv: array of arguments
 * Return: always 0 (success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}

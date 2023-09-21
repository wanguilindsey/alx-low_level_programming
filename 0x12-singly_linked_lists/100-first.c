#include <stdio.h>

void hoise(void) __attribute__ ((constructor));

/**
 * hoise - prints a sentence before the main
 * function is executed
 */
void hoise(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

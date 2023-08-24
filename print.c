#include "main.h"

/**
 * print - prints a string
 * @string: - input string
 */

void print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}

#include "main.h"

/**
 * parseCommandLine - function for parsing input
 * @input - user input
 * @command - pointer to store extracted command
 * @arguments - array to store extracted arguments
 */

void parseCommandLine(char *input, char **command, char *arguments[])
{
	char *arg;

	*command = strtok(input, " ");

	if (*command != NULL)
	{
		int argIndex;

		argIndex = 0;

		arg = strtok(NULL, " ");

		while (arg != NULL)
		{
			arguments[argIndex] = arg;
			arg = strtok(NULL, " ");
			argIndex++;
		}
		arguments[argIndex] = NULL;
	}
}

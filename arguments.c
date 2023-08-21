#include "main.h"

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

#include "main.h"
#include <errno.h>

/**
 * path - finds the full path of the command
 * @command: command to search for
 * @fullPath: a buffer to store the full path
 * @bufSize: size of the buffer
 * @return: returns 1 on success
 */

int path(char *command, char *fullPath, size_t bufSize)
{
	char *pathEnv;
	char *pathCopy;
	char *pathToken;

	pathEnv = getenv("PATH");
	if (pathEnv == NULL)
	{
		return (0);
	}

	pathCopy = strdup(pathEnv);
	if (pathCopy == NULL)
	{
		return (0);
	}

	pathToken = strtok(pathCopy, ":");
	while (pathToken != NULL)
	{
		snprintf(fullPath, bufSize, "%s/%s", pathToken, command);
		if (access(fullPath, X_OK) == 0)
		{
			free(pathCopy);
			return (1);
		}
		pathToken = strtok(NULL, ":");
	}

	free(pathCopy);
	return (0);
}

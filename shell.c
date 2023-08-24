#include "main.h"

int path(char *command, char *fullPath, size_t bufSize);
/**
 * main - function that immitates thompson shell functionality
 * @child: name of the child process
 * @input: takes in user input command
 */

int main(void)
{
	pid_t child;
	char *command;
	char *argv[MAX_INPUT_SIZE];
	char fullPath[MAX_INPUT_SIZE];

	while (1)
	{
		char input[MAX_INPUT_SIZE];

		printf("$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		parseCommandLine(input, &command, argv);

		if (command == NULL)
		{
			continue;
		}

		if (path(command, fullPath, sizeof(fullPath)))
		{
			argv[0] = fullPath;
			argv[1] = NULL;

			child = fork();
			if (child == -1)
			{
				perror("fork");
			}
			else if (child == 0)
			{
				execve(fullPath, argv, NULL);
				perror("execve");
				_exit(EXIT_FAILURE);
			}
			else
			{
				int status;

				while (waitpid(child, &status, 0) != child)
				{
					if (errno != EINTR)
					{
						perror("waitpid");
						break;
					}
				}
			}
		}
		else
		{
			printf("command not found: %s\n", command);
		}
	}
	return (0);
}

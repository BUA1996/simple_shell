#include "main.h"

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 32

/**
 * execute_command - function that executes the commands
 * @args - input
 * @token - token command
 * @command: - variable that takes the command entered
 */

void execute_command(char *command)
{
	char *args[MAX_ARGUMENTS];
	char *token;
	int arg_count = 0;

	token = strtok(command, " ");
	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
	}
	args[arg_count] = NULL;

	if (execve(args[0], args, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
/**
 * run_shell - main function for the shell
 * @command - variable for holding input
 */

void run_shell(void)
{
	char command[MAX_COMMAND_LENGTH];
	pid_t pid;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

	if (fgets(command, sizeof(command), stdin) == NULL)
	{
		printf("\n");
		break;
	}

	command[strcspn(command, "\n")] = '\0';

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execute_command(command);
	}
	else
	{
		wait(NULL);
	}

	}
}

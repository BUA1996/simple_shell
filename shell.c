#include "main.h"
#define MAX_INPUT_SIZE 256

int main(void)
{
    pid_t child;
    int num;
    char *arg;
    char *command;
    char argv;

    while (1)
    {

       	printf("$ ");
        
        char input[MAX_INPUT_SIZE];
        if (fgets(input, sizeof(input), stdin) == NULL)
	{
            break;
        }

        input[strcspn(input, "\n")] = '\0';

	command = strtok(input, " ");
        
        if (command == NULL) {
            continue;
        }
	
	*argv[MAX_INPUT_SIZE];
	argv[0] = command;

	num = 1;
	arg = strtok(NULL, " ");

	while (arg != NULL)
	{
		argv[num] = arg;
		arg = strtok(NULL, " ");
		num++;
	}

	argv[num] = NULL;

	child = fork();
        
        if (child == -1)
	{
            perror("fork");
        }
	else if (child == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
        }
	else
	{
		int status;
		waitpid(child, &status, 0);
        }
    }   
    return 0;
}

#ifndef main_h
#define main_h

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 256

int main(void);
void parseCommandLine(char *input, char **command, char *arguments[]);

#endif

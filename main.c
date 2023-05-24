#include "shell.h"

/**
 * main - Main function
 *
 * Return: Returns 0
 */

int main(void)
{
	char input[150];
	char *args[20];
	pid_t pid;
	int count;

	while (1)
	{
		if (fgets(input, 150, stdin) == NULL)
			exit(0);

		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
			break;
		else if (strcmp(input, "env") == 0)
		{
			print_environment();
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			count = parse_input(input, args);
			args[count] = NULL;

			search_command(args);
		}
		else
			wait(NULL);
	}
	return (0);
}

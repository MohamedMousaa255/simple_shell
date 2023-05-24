#include "shell.h"

/**
 * main - Main function
 * Return: Returns 0
 */

int main(void)
{

	char *argument[100];
	pid_t pid;
	int c;
	char comming_comand[400];

	while (1)
	{
		if (fgets(comming_comand, 400, stdin) == NULL)
			exit(0);

		comming_comand[strcspn(comming_comand, "\n")] = 0;

		if (strcmp(comming_comand, "exit") == 0)
			break;
		else if (strcmp(comming_comand, "env") == 0)
		{
			Print_env();
			continue;
		}

		pid = fork();
		if (pid == 0)
		{
			c = parseing(argument, comming_comand);
			argument[c] = NULL;

			command_execute(argument);
		}
		else
			wait(NULL);
	}
	return (0);
}

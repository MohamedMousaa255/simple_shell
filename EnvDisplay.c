#include "shell.h"


/**
 * print_environment - Prints the current environment
 *
 * Return: None
 */

void print_environment(void)
{
	char **environment = get_environment();
	int i = 0;

	while (environment[i] != NULL)
	{
		write(STDOUT_FILENO, environment[i], strlen(environment[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

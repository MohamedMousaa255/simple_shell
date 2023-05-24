#include "shell.h"


/**
 * print_environment - Printout  the current environment
 * Return: None
 */

void Print_env(void)
{	
	int counter = 0;
	char **env = get_environment();
	

	while (env[i] != NULL)
	{
		write(MY_STDOUT, env[i], strlen(env[i]));
		write(MY_STDOUT, "\n", 1);
		counter++;
	}
}

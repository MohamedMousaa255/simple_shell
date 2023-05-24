#include "shell.h"


/**
 * Print_env - Printout  environment
 * Return: Nothing
 */

void Print_env(void)
{
	int counter = 0;
	char **env = get_environment();


	while (env[counter] != NULL)
	{
		write(MY_STDOUT, env[counter], strlen(env[counter]));
		write(MY_STDOUT, "\n", 1);
		counter++;
	}
}

#include "shell.h"


/**
 * print_environment - Prints the current environment
 *
 * Return: None
 */

void print_environment(void)
{	
	int i = 0;
	char **env = get_environment();
	

	while (env[i] != NULL)
	{
		write(MY_STDOUT, env[i], strlen(env[i]));
		write(MY_STDOUT, "\n", 1);
		i++;
	}
}

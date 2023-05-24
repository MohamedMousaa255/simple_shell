#include "shell.h"
/**
 * parseing - divide  input to  commands and arg
 * @arg: arguments arr
 * @entercome:  Input to do parse for it
 * Return: argc
 */

int parseing(char **arg, char *entercome)
{
	int posion = 0;

	arg[posion] = strtok(entercome, " ");
	while (posion < 10 && arg[posion] != NULL)
	{
		posion++;
		arg[posion] = strtok(NULL, " ");
	}
	return (posion);
}

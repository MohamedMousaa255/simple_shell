#include "shell.h"

/**
 * get_environment - Retrieves a pointer to the current environment variables.
 * Return: Pointer to the environment variables.
 */

char **get_environment(void)
{

	return (environ);
}

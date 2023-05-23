#include "shell.h"
extern char **environ;
/**
 * print_environment - Prints the current environment
 *
 * Return: None
 */

void print_environment(void)
{
    int i;

    i = 0;
    while (environ[i] != NULL)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}


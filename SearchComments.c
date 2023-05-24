#include "shell.h"
/**
 * search_command - Searches and executes the specified command
 * @args: Array of arguments
 *
 * Return: None
 */

void search_command(char **args)
{
	char *command, *path, *path_copy, *directory, *full_command;

	command = strdup(args[0]);
	if (command == NULL)
		exit(1);

	if (access(command, X_OK) == -1)
	{
		path = getenv("PATH");
		path_copy = strdup(path);
		directory = strtok(path_copy, ":");

		while (directory != NULL)
		{
			full_command = malloc(strlen(directory) + strlen(command) + 2);
			if (full_command == NULL)
				exit(1);
			sprintf(full_command, "%s/%s", directory, command);
			if (access(full_command, X_OK) == 0)
			{
				args[0] = full_command;
				break;
			}
			free(full_command);
			directory = strtok(NULL, ":");
		}
		free(path_copy);
		free(command);
	}

	if (execvp(args[0], args) == -1)
	{
		printf("%s: command not found\n", args[0]);
		exit(1);
	}
}

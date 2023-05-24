#include "shell.h"
/**
 * command_execute - Searches and executes the specified command
 * @args: Array of arguments
 *
 * Return: None
 */

void command_execute(char **args)
{
	char *cm;
	char *location;
	char *cp_loc;
	char *directory;
	char *fcm;

	cm = strdup(args[0]);
	if (cm == NULL)
		exit(1);

	if (access(cm, X_OK) == -1)
	{
		location = getenv("PATH");
		cp_loc = strdup(location);
		directory = strtok(cp_loc, ":");

		while (directory != NULL)
		{
			fcm = malloc(strlen(directory) + strlen(cm) + 2);
			if (fcm == NULL)
				exit(1);
			sprintf(fcm, "%s/%s", directory, cm);
			if (access(fcm, X_OK) == 0)
			{
				args[0] = fcm;
				break;
			}
			free(fcm);
			directory = strtok(NULL, ":");
		}
		free(cp_loc);
		free(cm);
	}

	if (execvp(args[0], args) == -1)
	{
		printf("%s: command not found\n", args[0]);
		exit(1);
	}
}

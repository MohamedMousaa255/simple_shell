#include "shell.h"
/**
 * main - Main function
 *@argc: argument counter
 *@argv: argumentlist
 * Return: Returns 0
 */
int main(int argc, char *argv[])
{
	char **args = argv + 1;
	pid_t pid;
	int count;

	while (1)
	{
		if (argc < 2)
		{
			write(STDOUT_FILENO, "No command entered.\n", 20);
			break;
		}

		if (strcmp(args[0], "exit") == 0)
			break;
		else if (strcmp(args[0], "env") == 0)
		{
			print_environment();
			break;
		}

		pid = fork();
		if (pid == 0)
		{
			count = parse_input(argc, args);
			args[count] = NULL;

			search_command(args);
		}
		else
			wait(NULL);
		break;
	}

	return (0);
}

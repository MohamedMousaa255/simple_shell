#include "shell.h"

/**
 * parse_input - Parses user input into individual commands and arguments
 * @argc: User input to be parsed
 * @argv: Array of arguments
 *
 * Return: Number of commands and arguments
 */

int parse_input(int argc, char *argv[])
{
    int index = 0;
    
    while (index < argc && argv[index] != NULL)
    {
        index++;
    }
    
    return index;
}

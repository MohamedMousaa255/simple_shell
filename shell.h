#ifndef SHELL_H
#define SHELL_H

#include <unistd.h> /**for( _exit,access,chdir,close,execve,fork,_exit,
					*getpid,isatty,kill,open,read,write )**/
#include <stdio.h> /*for fflush*/
#include <stdlib.h> /*for (exit,free,malloc)*/
#include <dirent.h> /*for (closedir,opendir,readdir)*/
#include <string.h> /*for (strtok)*/
#include <signal.h> /*for (signal)*/
#include <sys/stat.h> /*for (stat,lstat,fstat) */
#include <errno.h> /*for (perror)*/
#include <sys/wait.h>/*for (wait,wait,pid,wait3,wait4)*/
#include <stdio.h> /*for using null*/
#include <unistd.h> /*access to POSIX API functions*/
#include <fcntl.h> /*file control options*/


char **get_environment(void);
void print_environment(void);
void search_command(char **args);
int parse_input(char *input, char **args);

extern char **environ;

#endif

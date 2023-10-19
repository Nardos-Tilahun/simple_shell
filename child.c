#include "our_shell.h"

/**
 * child - it evaluate the command it gets
 * @pro: the first argument
 * @first_arg: the first argument of the vector which has a command on it
 * @vec_arg: all the argument given by the commands
 * @genv: all the global environment
 */
void child(char *pro, char *first_arg, char *vec_arg[], char *genv[])
{
	int check = 0;
	int idx;

	signal(SIGUSR1, myexit_point);
	if (compath(first_arg, "exit"))
	{
		kill(getppid(), SIGUSR1);
		for (idx = 0; vec_arg[idx] != NULL; idx++)
                        free(vec_arg[idx]);
                free(vec_arg);
		exit(0);
	}
	check = execve(first_arg, vec_arg, genv);
	if (check == -1)
	{
		for (idx = 0; vec_arg[idx] != NULL; idx++)
			free(vec_arg[idx]);
		free(vec_arg);
		perror(pro);
		exit(1);
	}
}

#include "our_shell.h"

/**
 * evaluate - it evaluate the command it gets
 * @pro: - take the first argument
 * @first_arg: the first argument of the vector which has a command on it
 * @vec_arg: all the argument given by the commands
 * @genv: all the global environment
 * Return: the integer value to check the return status
 */
int evaluate(char *pro, char *first_arg, char *vec_arg[], char *genv[])
{
	pid_t son;
	int check = 0;
	/*int idx;*/

	signal(SIGUSR1, myexit_point);
	son = fork();
	if (son == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (son == 0)
	{
		child(pro, first_arg, vec_arg, genv);

	}
	else
	{
		waitpid(son, &check, 0);
		/*for (idx = 0; vec_arg[idx] != NULL; idx++)
			free(vec_arg[idx]);
		free(vec_arg);*/
	}
	return (WEXITSTATUS(check));
}

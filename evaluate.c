#include "our_shell.h"

/**
 * evaluate - it evaluate the command it gets
 * @first_arg: the first argument of the vector which has a command on it
 * @vec_arg: all the argument given by the commands
 * @genv: all the global environment
 * @pro: check the first argument of the shell
 * Return: integer value
 */
int evaluate(char *pro, char *first_arg, char **vec_arg, char **genv)
{
	pid_t son;
	int check;
	int idx;

	son = fork();
	if (son == -1)
	{
		perror("fork");
		exit(0);
	}
	else if (son == 0)
	{

		check = execve(first_arg, vec_arg, genv);
		if (check == -1)
		{
			for (idx = 0; vec_arg[idx] != NULL; idx++)
				free(vec_arg[idx]);
			free(vec_arg);
			perror(pro);
			exit(0);
		}
	}
	else
	{
		waitpid(son, &check, 0);
		for (idx = 0; vec_arg[idx] != NULL; idx++)
			free(vec_arg[idx]);
		free(vec_arg);
	}
	return (WEXITSTATUS(check));

}

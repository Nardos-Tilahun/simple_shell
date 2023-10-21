#include "our_shell.h"

/**
 * input_ch - predefined path
 * @comand: strings
 * @input:  (to be freed)
 * @c:Shell Found
 * @vector: argument
 * Return: zero
 */

int input_ch(char **comand, char *input, int c, char **vector)
{
	int ostat;
	pid_t pid;

	if (!*comand)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (!pid)
	{
		if (mycmpstrn(*comand, "./", 2) != 0 && mycmpstrn(*comand, "/", 1) != 0)
			comad_place(comand);
		if (access(comand[0], R_OK) != 0)
		{
			show_err(comand[0], c, vector);
			arrfree(comand, input);
			exit(127);
		}
		if (execve(*comand, comand, environ) == -1)
			return (2);
		else
			return (0);
	}
	wait(&ostat);
	if (WIFEXITED(ostat))
	{
		if (WEXITSTATUS(ostat) == 0)
			return (0);
		else if (WEXITSTATUS(ostat) == 2)
			return (2);
		else if (WEXITSTATUS(ostat) == 127)
			return (127);
	}
	return (127);
}

/**
 * signal_checker - check the signal
 * @cs: arrive signal
 */

void signal_checker(int cs)
{
	if (cs == SIGINT)
	{
		myprinter("\n$ ");
	}
}

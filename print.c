#include "our_shell.h"

/**
 * p_num - number to be printed
 * @num: integer
 */

void p_num(unsigned int num)
{
	unsigned int xo = num;

	if ((xo / 10) > 0)
		p_num(xo / 10);

	mycharput(xo % 10 + '0');
}

/**
 * p_num_int - string to number
 * @num: to printed
 */

void p_num_int(int num)
{
	unsigned int xo = num;

	if (num < 0)
	{
		mycharput('-');
		xo = -xo;
	}
	if ((xo / 10) > 0)
		p_num(xo / 10);

	mycharput(xo % 10 + '0');
}

/**
 * print_echo - Executes built-in echo function
 * @commd: Parsed Command
 * Return: fdsa
 */

int print_echo(char **commd)
{
	pid_t pid;
	int stat;

	pid = fork();
	if (pid == 0)
	{
	if (execve("/bin/echo", commd, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		return (-1);
	do {
		waitpid(pid, &stat, WUNTRACED);
	} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	return (1);
}
/**
 * printing - function that prints '$' to standard output
 */
void printing(void)
{
	myprinter("$ ");
}


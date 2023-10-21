#include "our_shell.h"
/**
 * change_dir - Changes directory
 * @commd: Parsed command
 * @stat: how the stat
 * Return: success checking
 */
int change_dir(char **commd, int stat)
{
	int num = -1;
	char cwd[PATH_MAX];
	(void) stat;

	if (commd[1] == NULL)
		num = chdir(getenv("HOME"));
	else if (mycmpstr(commd[1], "-") == 0)
	{
		num = chdir(getenv("OLDPWD"));
	}
	else
		num = chdir(commd[1]);

	if (num == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (num != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * distrenv -string of environment
 * @parcd: change the command
 * @stat: status of last command executed
 * Return: the status
 */

int distrenv(char **parcd, int stat)
{
	size_t i;
	int len;
	(void) parcd;
	(void) stat;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = mylenstr(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * echo_bul - execute echo cases
 * @st: statue of last command executed
 * @cmd: parsed command
 * Return: Always 1 Or execute normal echo
 */
int echo_bul(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (mycmpstrn(cmd[1], "$?", 2) == 0)
	{
		p_num_int(st);
		myprinter("\n");
	}
	else if (mycmpstrn(cmd[1], "$$", 2) == 0)
	{
		p_num(pid);
		myprinter("\n");
	}
	else if (mycmpstrn(cmd[1], "$PATH", 5) == 0)
	{
		path = shomyenv("PATH");
		myprinter(path);
		myprinter("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (1);
}
/**
 * myhist_dis - display myhist of user input on simple_shell
 * @c: parsed command
 * @st: status of last command executed
 * Return: 0 success or -1 if fail
 */
int myhist_dis(__attribute__((unused))char **c, __attribute__((unused))int st)
{
	char *filename = ".simple_shell_myhist";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = myi_to_a(counter);
		myprinter(er);
		free(er);
		myprinter(" ");
		myprinter(line);
	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}

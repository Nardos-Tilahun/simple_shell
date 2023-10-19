#include "our_shell.h"

/**
 * getcmd - getcommand
 * @newcmd: array of command
 * @env: environment
 * Return: integer to check the file exist or not
 */

int getcmd(char ***newcmd, char *env[])
{
	char *fcmd, *scmd, *home, *cwd, bpwd[2048];
	static char *cpath;
	int ok;

	fcmd = copy_me((*newcmd)[0]);
	cpath = getcwd(bpwd, 2048);
	if (cpath == NULL)
		return (1);
	if (compath(fcmd, "pwd"))
	{
		write(STDIN_FILENO, cpath, lenstr(cpath));
		write(STDIN_FILENO, "\n", 1);
		free(fcmd);
		return (0);
	}
	else if (compath(fcmd, "cd"))
	{
		scmd = copy_me((*newcmd)[1]);
		home = checkenv(env, "HOME=");
		if (home && (scmd == NULL || compath(scmd, "$HOME")))
		{
			cwd = getcwd(bpwd, 2048);
			setmyenv("OLDPWD", cwd, 1, &env);
			chdir(home);
			setmyenv("PWD", home, 1, &env);
			return (0);
		}
		else
		{
			ok = hgetcmd(scmd, env);
			if (!ok)
				return (0);
		}
	free(scmd);
	}
	free(fcmd);
	return (1);
}

/**
 * hgetcmd- find the file in the directory
 * @scmd: second argument
 * @env: environment
 * Return: integer to check the file exist or not
 */
int hgetcmd(char *scmd, char *env[])
{
	char bpwd[2048], *owd, *cwd;
	int ok;

	ok = compath(scmd, "-");
	if (ok)
	{
		cwd = getcwd(bpwd, 2048);
		owd = checkenv(env, "OLDPWD=");
		setmyenv("OLDPWD", cwd, 1, &env);
		ok = chdir(owd);
		if (ok == -1)
			return (1);
		cwd = getcwd(bpwd, 2048);
		setmyenv("PWD", cwd, 1, &env);
		write(STDIN_FILENO, cwd, lenstr(cwd));
		write(STDIN_FILENO, "\n", 1);
		return (0);
	}
	ok = access(scmd, X_OK);
	if (ok == -1)
		return (1);
	owd = getcwd(bpwd, 2048);
	setmyenv("OLDPWD", owd, 1, &env);
	ok = chdir(scmd);
	if (ok == -1)
		return (1);
	cwd = getcwd(bpwd, 2048);
	setmyenv("PWD", cwd, 1, &env);
	return (0);
}

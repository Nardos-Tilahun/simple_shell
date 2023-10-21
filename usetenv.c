#include "our_shell.h"

/**
 * usetenv - getcommand
 * @newcmd: array of command
 * @envr: environment
 * Return: integer to check the file exist or not
 */

int usetenv(char ***newcmd, char ***envr)
{
	char *fcmd, *scmd, *tcmd, **env;
	int ok, overme = 1;

	env = *envr;
	fcmd = copy_me((*newcmd)[0]);
	if (compath(fcmd, "setenv") || compath(fcmd, "unsetenv"))
	{
		scmd = copy_me((*newcmd)[1]);
		if (!scmd)
			return (1);
		else if (compath(fcmd, "unsetenv"))
		{
			if ((*newcmd)[2])
				return (1);
			ok = unsetmyenv(scmd, &env);
			if (!ok)
				return (0);
		}
		else
		{
			tcmd = copy_me((*newcmd)[2]);
			if (!tcmd || ((*newcmd)[3]))
				return (1);
			ok = setmyenv(scmd, tcmd, overme, &env);
			if (!ok)
				return (0);
		}
	}
	free(fcmd);
	return (1);
}

/**
 * setmyenv - getcommand
 * @name: name of the env
 * @value: value of the env
 * @overme: overwrite or not
 * @envr: environment
 * Return: integer to check the file exist or not
 */

int setmyenv(char *name, char *value, int overme, char ***envr)
{
	char *changenv, **newenv, *copy, **env;
	int i = 0, l;

	env = *envr;
	for (i = 0; env[i] != NULL; i++)
	{
		copy = copy_me(env[i]);
		if (compath((tokenv(copy))[0], name))
		{
			if (overme)
			{
				changenv = strconc(strconc(name, "="), value);
				if (changenv)
				{
					env[i] = copy_me(changenv);
					break;
				}
			}
		}
	}
	if (env[i] == NULL)
	{
		newenv = (char **)malloc((sizeof(char *) * (i + 2)));
		if (!env)
		{
			perror(name);
			return (0);
		}
		for (i = 0; env[i]; i++)
		{
			newenv[i] = copy_me(env[i]);
		}
		newenv[i++] = strconc(strconc(name, "="), value);
		newenv[i] = NULL;
		l = i;
		for (i = 0; i < l; i++)
			env[i] = newenv[i];
		env[i] = NULL;
	}
	return (0);
}

/**
 * unsetmyenv - getcommand
 * @name: name of the env
 * @envr: environment
 * Return: integer to check the file exist or not
 */

int unsetmyenv(char *name, char ***envr)
{
	int i = 0, check = 0;
	char **env;

	env = *envr;
	for (i = 1; env[i - 1] != NULL; i++)
	{
		if (compath(((tokenv(env[i - 1]))[0]), name))
		{
			if (env[i] == NULL)
			{
				env[i - 1] = NULL;
				return (0);
			}
			env[i - 1] = env[i];
			check = 1;
			i++;
		}
		if (check)
			env[i - 1] = env[i];
	}
	if (!check)
		return (1);
	return (0);
}

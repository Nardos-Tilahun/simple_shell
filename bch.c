#include "our_shell.h"

/**
 * statbuilt - Checks if parsed command in built-in
 * @cmd: change command to be check
 * Return: 0 Succes -1 Fail
 */

int statbuilt(char **cmd)
{
	builtin fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"env", NULL},
		{"myhist", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}
	while ((fun + i)->commd)
	{
		if (mycmpstr(cmd[0], (fun + i)->commd) == 0)
			return (0);
		i++;
	}
	return (-1);
}

/**
 * checkinbuilt - Handles predefined built in commands
 * @cmd: Array of parsed command strings
 * @st: Status of last execution
 * Return: -1 Failure 0 Success
 */

int checkinbuilt(char **cmd, int st)
{
	builtin built_in[] = {
		{"cd", change_dir},
		{"env", distrenv},
		{"help", herehelp},
		{"echo", echo_bul},
		{"myhist", myhist_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((built_in + i)->commd)
	{
		if (mycmpstr(cmd[0], (built_in + i)->commd) == 0)
		{
			return ((built_in + i)->function(cmd, st));
		}
		i++;
	}
	return (-1);
}

/**
 * exiting - Exit Status for built-in commands
 * @cmd: Array of parsed command strings
 * @input: Input recieved from user (to be freed)
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Shell execution count
 * @stat: Exit status
 */

void exiting(char **cmd, char *input, char **argv, int c, int stat)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(stat);
	}
	while (cmd[1][i])
	{
		if (myalphais(cmd[1][i++]) != 0)
		{
			errpre(argv, c, cmd);
			free(input);
			free(cmd);
			exit(2);
		}
		else
		{
			status = _atoi(cmd[1]);
			if (status == 2)
			{
				errpre(argv, c, cmd);
				free(input);
				free(cmd);
				exit(status);
			}
			free(input);
			free(cmd);
			exit(status);
		}
	}
}

#include "our_shell.h"

/**
 * mainhelp - second entry point of the program
 * @ar_s: - count the number of argument
 * @ncmd: - array of a string in the command
 * @our:- the environment variable
 * @s: - status of the function
 * @ch: character
 * Return: integer whether it is success or not
 */
int mainhelp(char **ar_s[], char ***our, char **ncmd, char ***ch, int *s)
{
	char **all_path, ***new_cmd, *new_path, *newP,  **oure;
	int i, check1 = 1, check2 = 1;

	oure = *our;
	if (compath(*ncmd, "env"))
	{
		i = 0;
		while (oure[i] != NULL)
		{
			write(STDIN_FILENO, oure[i], lenstr(oure[i]));
			write(STDIN_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}
	new_cmd = &(*ch);
	check1 = usetenv(new_cmd, &oure);
	if(!check1)
	{
		free(new_cmd);
		return (1);
	}
	check2 = getcmd(new_cmd, oure);
	if (!check1 || !check2)
	{
		free(new_cmd);
		return (1);
	}
	new_path = checkenv(oure, "PATH");
	all_path = tokp(new_path);
	if (!all_path)
		return (1);
	newP = checkcmd(all_path, *ch[0]);
	*new_cmd[0] =  newP;
	if (newP == NULL)
	{
		if (compath(*ncmd, "exit"))
			*new_cmd[0] = *ncmd;
		*ar_s[0] = *ncmd;
	}
	*s = evaluate(*ar_s[0], *new_cmd[0], *new_cmd, NULL);
	for (i =  0; all_path[i]; i++)
		free(all_path[i]);
	free(all_path);
	free(new_path);
	return (1);
}

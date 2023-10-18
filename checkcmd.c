#include "our_shell.h"

/**
 * checkcmd - find the file in the directory
 * @all_path: uses a line of string of the command line
 * @comd: the file name we want to find
 * Return: integer to check the file exist or not
 */
char *checkcmd(char **all_path, char *comd)
{
	char *concpath = NULL;
	int i = 0, namecheck;
	int pathcheck;

	if (!all_path)
		return (NULL);
	for (i = 0; all_path[i] != NULL; i++)
	{
		pathcheck = isfullpath(all_path[i], comd);
		if (pathcheck)
		{
			concpath = comd;
			break;
		}
	}
	if (all_path[i] == NULL)
	{
		for (i = 0; all_path[i] != NULL; i++)
		{
			namecheck = filefind(all_path[i], comd);
			if (namecheck)
			{
				concpath = concat(all_path[i], comd);
				break;
			}
		}
		if (all_path[i] == NULL)
			return (NULL);
	}
	return (concpath);
}

#include "our_shell.h"

/**
 * newpath - find the file in the directory
 * @all_path: uses a line of string of the command line
 * @comd: the file name we want to find
 * Return: integer to check the file exist or not
 */
char *newpath(char **all_path, char *comd)
{
	char *concpath = NULL;
	int i;

	if (!all_path)
		return (NULL);
	for (i = 0; all_path[i] != NULL; i++)
	{

		if (!filefind(all_path[i], comd))
			continue;
		else
		{
			concpath = concat(all_path[i], comd);
			break;
		}
	}
	return (concpath);
}

#include "our_shell.h"

/**
 * newpath - create a new path including a new file
 * @all_path: the path only to the directory
 * @comd: the command file name to concatinate with
 * Return: character array of new path returned
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

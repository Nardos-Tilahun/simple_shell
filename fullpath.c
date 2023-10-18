#include "our_shell.h"

/**
 * isfullpath - find the file in the directory
 * @each_line: uses a line of string of the command line
 * @filename: the file name we want to find
 * Return: integer to check the file exist or not
 */
int isfullpath(char *each_line, char *filename)
{
	char *fullpath = NULL;
	DIR *dirpoint = NULL;
	struct dirent *dread = NULL;
	int check = 0;

	dirpoint = opendir(each_line);
	if (dirpoint == NULL)
		return (0);
	while ((dread = readdir(dirpoint)) != NULL)
	{
		fullpath = concat(each_line, (*dread).d_name);
		if (fullpath)
		{
			check = compath(fullpath, filename);
			free(fullpath);
			if (check)
			{
				closedir(dirpoint);
				return (1);
			}
		}
	}
	closedir(dirpoint);
	return (check);
}

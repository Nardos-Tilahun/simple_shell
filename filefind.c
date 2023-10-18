#include "our_shell.h"

/**
 * filefind - find the file in the directory
 * @each_line: uses a line of string of the command line
 * @filename: the file name we want to find
 * Return: integer to check the file exist or not
 */
int filefind(char *each_line, char *filename)
{
	int check = 0;
	DIR *dirpoint = NULL;
	struct dirent *dread = NULL;

	dirpoint = opendir(each_line);
	if (dirpoint == NULL)
		return (0);
	while ((dread = readdir(dirpoint)) != NULL)
	{
		check = compath((*dread).d_name, filename);
		if (check)
		{
			closedir(dirpoint);
			return (1);
		}
	}
	closedir(dirpoint);
	return (check);
}


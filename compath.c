#include "our_shell.h"

/**
 * compath- entry point of the program
 * @first: - count the number of argument
 * @second: - array of a string in the command
 * Return: integer whether it is success or not
 */
int compath(char *first, char *second)
{
	int i = 0;

	if (!(first && second))
	{
		return (0);
	}
	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	if (second[i] == '\0' && first[i] == '\0')
		return (1);
	return (0);
}

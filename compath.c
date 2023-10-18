#include "our_shell.h"

/**
 * compath - to compare two string
 * @first: - first string
 * @second: - second string
 * Return: integer whether it is match or not
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

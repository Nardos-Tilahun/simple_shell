#include "our_shell.h"

/**
 * strcompare- it compare the path to second string
 * @first: - first string which is the path
 * @second: - second string that we want to find from first
 * Return: new character array that exclude the second string
 */
char *strcompare(char *first, char *second)
{
	int i = 0;

	if (!(first && second))
		return (NULL);
	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}
	if (second[i] != '\0')
		return (NULL);
	return (first + i);
}

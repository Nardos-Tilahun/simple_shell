#include "our_shell.h"

/**
 * strcompare- entry point of the program
 * @first: - count the number of argument
 * @second: - array of a string in the command
 * @move: - pointer to int
 * Return: integer whether it is success or not
 */
char *strcompare(char *first, char *second, int *move)
{
	*move = 0;

	if (!(first && second))
	{
		return (NULL);
	}
	while (first[*move] != '\0')
	{
		if (first[*move] != second[*move])
			break;
		(*move)++;
	}
	if (second[*move] != '\0')
		return (NULL);
	return (first + *move);
}

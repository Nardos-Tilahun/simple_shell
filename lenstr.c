#include "our_shell.h"

/**
 * lenstr- count the length of the string
 * @first:- it count this string
 * Return: integer the index or zero
 */
int lenstr(char *first)
{
	int i = 0;

	if (!first || !first[i])
		return (0);
	while (first[i] != '\0')
		i++;
	return (i);
}

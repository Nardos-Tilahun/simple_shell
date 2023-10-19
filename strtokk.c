#include "our_shell.h"

/**
 * strtokk - string
 * @first: -first
 * @dmeter: demeter
 * Return: - string
 */
char *strtokk(char *first, char *dmeter)
{
	int i = 0;
	int check = 0;
	static char *move;
	char *next;

	if (first != NULL)
	{
		move = first;
	}
	else
		next = move;

	while (*move)
	{
		for (i = 0; dmeter[i] != '\0'; i++)
		{
			if (*move == dmeter[i])
			{
				*move = '\0';
				move++;
				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
		move++;
	}
	if (first != NULL)
		return (first);
	else if (*next != '\0')
		return (next);
	move = NULL;
	return (move);
}

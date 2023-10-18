#include "our_shell.h"

/**
 * copy_me- it copy the string to another string in heap memory
 * @each_line: uses a line of string that you want to copy
 *
 * Return: charcter pointer to pointer array of string that is copied
 */
char *copy_me(char *each_line)
{
	char *each_word;
	int idx, length;

	if (!each_line)
		return (0);
	for (idx = 0; each_line[idx] != '\0'; idx++)
		;
	length = idx;
	each_word = (char *)malloc(sizeof(char) * (idx + 1));
	if (each_word == NULL)
	{
		free(each_line);
		return (0);
	}
	for (idx = 0; idx < length ; idx++)
		each_word[idx] = each_line[idx];
	each_word[idx] = '\0';
	return (each_word);
}


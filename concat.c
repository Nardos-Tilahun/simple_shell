#include "our_shell.h"

/**
 * concat - reads each line using getline function
 * @str1: string one
 * @str2: string two
 * Return: charcter pointer which point to the first word
 */
char *concat(char *str1, char *str2)
{
	int i, j, len1, len2;
	char *new;

	if (!(str1 && str2))
		return (NULL);
	for (i = 0; str1[i] != '\0'; i++)
		;
	len1 = i;
	for (j = 0; str2[j] != '\0'; j++)
		;
	len2 = j;
	new = (char *)malloc(sizeof(char) * (len1 + len2 + 2));
	if (!new)
		return (NULL);
	for (i = 0; str1[i] != '\0'; i++)
		new[i] = str1[i];
	new[i++] = '/';
	for (j = 0; str2[j] != '\0'; j++, i++)
		new[i] = str2[j];
	new[i] = '\0';
	return (new);
}

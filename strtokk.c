#include "our_shell.h"
/**
 * is_delim - hanle separetor
 * @checking: integer checker
 * @s:	used as delimiter
 * Return: integer to succes
 */
unsigned int is_delim(char checking, const char *s)
{
	unsigned int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (checking == s[i])
			return (1);
	}
	return (0);
}
/**
 * mytokstr - a function split the word using delimeter
 * @s: argumnet string
 * @delim: parameter handler
 * Return: pointer
 */
char *mytokstr(char *s, const char *delim)
{
	static char *to;
	static char *new_token;
	unsigned int a;

	if (s != NULL)
		new_token = s;
	to = new_token;
	if (to == NULL)
		return (NULL);
	for (a = 0; to[a] != '\0'; a++)
	{
		if (is_delim(to[a], delim) == 0)
			break;
	}
	if (new_token[a] == '\0' || new_token[a] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	to = new_token + a;
	new_token = to;
	for (a = 0; new_token[a] != '\0'; a++)
	{
		if (is_delim(new_token[a], delim) == 1)
			break;
	}
	if (new_token[a] == '\0')
		new_token = NULL;
	else
	{
		new_token[a] = '\0';
		new_token = new_token + a + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (to);
}

#include "our_shell.h"

/**
 * tokenv - separate each words from each line of the input
 * @each_line: uses a line of string of the command line
 * Return: charcter pointer to pointer array of string
 */
char **tokenv(char *each_line)
{
	char **env, *name, *value, *copyone, *copytwo;
	int i;

	env = (char **)malloc(sizeof(char *) * 3);
	if (env == NULL)
	{
		free(each_line);
		return (NULL);
	}
	copyone = copy_me(each_line);
	copytwo = copy_me(each_line);
	for (i = 0; copyone[i] != '='; i++)
		;
	copyone[i] = '=';
	name = copyone;
	name = copy_me(copytwo);
	for (i = 0; *(copytwo++); i++)
	{
		if (*copytwo == '=')
		{
			*copytwo = '\0';
			copytwo++;
			break;
		}
	}
	value = copytwo;
	name = copytwo - i - 2;
	env[0] = name;
	env[1] = value;
	env[2] = NULL;
	return (env);
}

#include "our_shell.h"

/**
 * checkenv - checking the environment
 * @our_env: - hold the environment
 * Return: character array that return the new path
 */
char *checkenv(char *our_env[])
{
	char *path, *new_path;
	int i = 0;

	while (our_env[i] != NULL)
	{
		path = strcompare(our_env[i], "PATH=");
		if (path == NULL)
		{
			i++;
			continue;
		}
		else
			break;
	}
	if (our_env[i] == NULL)
		return (NULL);
	new_path = copy_me(path);
	return (new_path);
}

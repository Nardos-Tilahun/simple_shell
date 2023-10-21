#include "our_shell.h"
/**
 * comad_place - place where command accepts
 * @cmd: command
 * Return: status check
 */
int comad_place(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = shomyenv("PATH");
	value = mytokstr(path, ":");
	while (value != NULL)
	{
		cmd_path = made(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = mydcopystr(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = mytokstr(NULL, ":");
	}
	free(path);
	free(value);
	return (1);
}
/**
 * made - Build command
 * @token: Executable command
 * @value: Directory conatining Command
 * Return: Parsed full path of command or NULL if failed
 */
char *made(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = mylenstr(value) + mylenstr(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		free(cmd);
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = mycatstr(cmd, value);
	cmd = mycatstr(cmd, "/");
	cmd = mycatstr(cmd, token);

	return (cmd);
}
/**
 * shomyenv - the value of environment variable by name
 * @name: Environment variable name
 * Return: The value of the environment variable or NULL if failed
 */
char *shomyenv(char *name)
{
	size_t name_len, value_len;
	char *value;
	int i, j, k;

	name_len = mylenstr(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (mycmpstrn(name, environ[i], name_len) == 0)
		{
			value_len = mylenstr(environ[i]) - name_len;
			value = malloc(sizeof(char) * value_len);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (k = name_len + 1; environ[i][k]; k++, j++)
			{
				value[j] = environ[i][k];
			}
			value[j] = '\0';

			return (value);
		}
	}
	return (NULL);
}

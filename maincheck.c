#include "our_shell.h"

/**
 * main - entry point of the program
 * @count: - count the number of argument
 * @arg_str: - array of a string in the command
 * @our_env:- the environment variable
 * Return: integer whether it is success or not
 */
int main(int count, char *arg_str[], char *our_env[])
{
	char **ch, **all_path, ***new_cmd, *te, *new_path, *newP, *notcmd;
	int status = 0, *p = &count, i = 0;

	*p = 0;
	do {
		te = read_for_me();
		if (te == NULL)
			return (status);
		ch = separate(te);
		if (!ch)
		{
			free(te);
			continue;
		}
		notcmd = copy_me(ch[0]);
		if (compath(notcmd, "env"))
		{
			i = 0;
			while (our_env[i] != NULL)
			{
				write(1, our_env[i], lenstr(our_env[i]));
				write(1, "\n", 1);
				i++;
			}
			for (i = 0; ch[i]; i++)
				free(ch[i]);
			free(ch);
			free(notcmd);
			continue;
		}
		new_cmd = &ch;
		new_path = checkenv(our_env);
		all_path = tokp(new_path);
		if (!all_path)
		{
			free(*new_cmd);
			free(new_path);
			continue;
		}
		newP = checkcmd(all_path, ch[0]);
		*new_cmd[0] =  newP;
		if (newP == NULL)
		{
			if (compath(notcmd, "exit"))
				*new_cmd[0] = notcmd;
			arg_str[0] = notcmd;
		}
		status = evaluate(arg_str[0], *new_cmd[0], *new_cmd, NULL);
		for(i = 0; all_path[i]; i++)
			free(all_path[i]);
		free(all_path);
		free(new_path);
		free(notcmd);
		free(te);
	} while (1);
	return (0);
}

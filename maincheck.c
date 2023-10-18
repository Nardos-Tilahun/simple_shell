#include "our_shell.h"

/**
 * main - entry point of the program
 * @count: - count the number of argument
 * @arg_str: - array of a string in the command
 * @our_env: - environmental variable
 * Return: integer whether it is success or not
 */
int main(int count, char *arg_str[], char *our_env[])
{
	char **ch, **all_path, ***new_cmd;
	char *te, *path, *new_path, *newP, *notcmd;
	int status = 0, *p = &count, i = 0, move;
	*p = 0;
	do {
		te = read_for_me();
		if (te == NULL)
			return (status);
		ch = separate(te);
		if (!ch)
			continue;
		notcmd = copy_me(ch[0]);
		new_cmd = &ch;
		i = 0;
		move = 0;
		while (our_env[i] != NULL)
		{
			path = strcompare(our_env[i], "PATH=", &move);
			if (path == NULL)
			{
				i++;
				continue;
			}
			else
				break;
		}
		new_path = copy_me(path);
		if (our_env[i] == NULL)
			continue;
		all_path = tokp(new_path);
		if (!all_path)
			continue;
		newP = checkcmd(all_path, ch[0]);
		*new_cmd[0] =  newP;
		if (newP == NULL)
			arg_str[0] = notcmd;
		status = evaluate(arg_str[0], *new_cmd[0], *new_cmd, NULL);
	} while (1);
	return (0);
}

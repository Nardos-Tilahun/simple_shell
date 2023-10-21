#include "our_shell.h"

/**
 * main - entry point of the program
 * @count: - count the number of argument
 * @arg_str: - array of a string in the command
 * @our_env:- the environment variable
 * Return: integer whether it is success or not
 */

int main(int count, char *arg_str[], char **our_env)
{
	char **ch, *te, *notcmd;
	int status = 0, *p = &count, check = 0, idx;

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
		check = mainhelp(&arg_str, &our_env, &notcmd, &ch, &status);
		free(notcmd);
		if (ch)
		{
			for (idx = 0; ch[idx] != NULL; idx++)
				free(ch[idx]);
			free(ch);
		}
		if (check == 1)
			continue;


	} while (1);
	return (0);
}

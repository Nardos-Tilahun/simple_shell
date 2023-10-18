#include "our_shell.h"

/**
 * main - entry point of the program
 * @count: - count the number of argument
 * @arg_str: - array of a string in the command
 * Return: integer whether it is success or not
 */
int main(int count, char **arg_str)
{
	char **ch;
	char *te;
	int status = 0;
	int *p = &count;
	*p = 0;

	do {
		te = read_for_me();
		if (te == NULL)
			return (status);
		ch = separate(te);
		if (!ch)
		{
			continue;
		}
		status = evaluate(arg_str[0], ch[0], ch, NULL);
	} while (1);
	return (0);
}

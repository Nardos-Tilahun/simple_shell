#include "our_shell.h"

/**
 * read_for_me - reads each line using getline function
 * Return: charcter pointer which point to the first word
 */
char *read_for_me()
{
	char *read_me = NULL;
	size_t bufr_count = 0;
	ssize_t count_me = 0;

	if (isatty(0))
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	count_me = getline(&read_me, &bufr_count, stdin);
	if (!read_me || count_me == -1)
	{
		if (read_me)
			free(read_me);
		if (isatty(0))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		return (NULL);
	}
	return (read_me);
}

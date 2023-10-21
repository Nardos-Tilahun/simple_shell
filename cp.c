#include "our_shell.h"

/**
 * chan_cmd - Parses the command recieved from stdin
 * @input: String gathered from stdin
 * Return: Parsed strings to be used as arguments
 */

char **chan_cmd(char *input)
{
	char **arguments;
	char *argument;
	int i;
	int buffsize = BUFSIZE;

	if (input[0] == ' ' && input[mylenstr(input)] == ' ')
		exit(0);
	if (input == NULL)
		return (NULL);
	arguments = malloc(sizeof(char *) * buffsize);
	if (!arguments)
	{
		free(arguments);
		perror("hsh");
		return (NULL);
	}
	argument = mytokstr(input, "\n\t\r\a ");
	for (i = 0; argument; i++)
	{
		arguments[i] = argument;
		argument = mytokstr(NULL, "\n\t\r\a ");
	}
	arguments[i] = NULL;

	return (arguments);
}

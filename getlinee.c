#include "our_shell.h"
/**
* catchline - read input user
* Return: return buffer
*/
char *catchline()
{
	int i, rd, buffsize = BUFSIZE;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
			return (newline(buffer));
		if (i >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = handspace(buffer);
	free(buffer);
	ignore(buf);
	return (buf);
}
/**
 * newline - enter key handler
 * @string: string to hold
 * Return: pointer
 */
char *newline(char *string)
{
	free(string);
	return ("\0");
}

/**
 * handspace - space tab handler
 * @str: string for input
 * Return: pointer
 */
char *handspace(char *str)
{
	int i, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (mylenstr(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; str[i] == ' '; i++)
		;
	for (; str[i + 1] != '\0'; i++)
	{
		buff[j] = str[i];
		j++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
/**
 * ignore - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void ignore(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}

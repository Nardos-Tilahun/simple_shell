#include "our_shell.h"

/**
 * splits - function that Split command recieved from stdin by ;
 * @in: String from stdin
 * Return: Parsed strings to be used as commands
 */

char **splits(char *in)
{
	char **coms;
	char *mand;
	int a;
	int bu = BUFSIZE;

	if (in[0] == ' ' && in[mylenstr(in)] == ' ')
		exit(0);
	if (in == NULL)
		return (NULL);
	coms = malloc(sizeof(char *) * bu);
	if (!coms)
	{
		free(coms);
		perror("hsh");
		return (NULL);
	}
	mand = mytokstr(in, ";&");
	for (a = 0; mand; a++)
	{
		coms[a] = mand;
		mand = mytokstr(NULL, ";&");
	}
	coms[a] = NULL;

	return (coms);
}

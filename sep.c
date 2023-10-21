#include "our_shell.h"

/**
 * splits - Separates command recieved from stdin by ;
 * @in: String from stdin
 * Return: Parsed strings to be used as commands
 */

char **splits(char *in)
{
	char **coms;
	char *mand;
	int i;
	int buffsize = BUFSIZE;

	if (in[0] == ' ' && in[mylenstr(in)] == ' ')
		exit(0);
	if (in == NULL)
		return (NULL);
	coms = malloc(sizeof(char *) * buffsize);
	if (!coms)
	{
		free(coms);
		perror("hsh");
		return (NULL);
	}
	mand = mytokstr(in, ";&");
	for (i = 0; mand; i++)
	{
		coms[i] = mand;
		mand = mytokstr(NULL, ";&");
	}
	coms[i] = NULL;

	return (coms);
}

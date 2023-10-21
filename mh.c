#include "our_shell.h"
#include "our_shell.h"
/**
 *relloc - allocate memory again
 *@p: void which allocate
 *@si: original size
 *@siz: the new size argument
 *Return: viod pointer
 */
void *relloc(void *p, unsigned int si, unsigned int siz)
{
	void *tr;

	if (siz == si)
		return (p);
	if (!siz && p)
	{
		free(p);
		return (NULL);
	}
	tr = malloc(siz);
	if (tr == NULL)
	{
		free(tr);
		return (NULL);
	}
	if (!p)
	{
		fillarr(tr, '\0', siz);
		free(p);
	}
	else
	{
		mycpymem(tr, p, si);
		free(p);
	}
	return (tr);
}
/**
 * arrfree - function that allocated free memory
 * @cm: pointer array argument
 * @c_line: argument char pointer
 * Return: Void
 */
void arrfree(char **cm, char *c_line)
{
	free(cm);
	free(c_line);
	cm = NULL;
	c_line = NULL;
}
/**
 * mycpymem - from source to destination copy memory bytes
 *@es: final destination pointer
 *@rc: origin pointer
 *@nu: size to be copied
 *Return: pointer to destination
 */
char *mycpymem(char *es, char *rc, unsigned int nu)
{
	unsigned int a;

	for (a = 0; a < nu; a++)
	{
		es[a] = rc[a];
	}
	return (es);
}
/**
 * fillarr - using by constant byte fill array
 *@at: argument pointer void
 *@lem: argument integer
 *@width: length for int
 *Return: void pointer
 */
void *fillarr(void *at, int lem, unsigned int width)
{
	char *pl = at;
	unsigned int b = 0;

	while (b < width)
	{
		*pl = lem;
		pl++;
		b++;
	}
	return (at);
}
/**
 * mycal_oc - for an array using malloc allocate memory
 *@ize: agument size
 *Return: void pointer
 */
void *mycal_oc(unsigned int ize)
{
	char *j;
	unsigned int b;

	if (ize == 0)
	return (NULL);
	j = malloc(ize);
	if (j == NULL)
	return (NULL);
	for (b = 0; b < ize; b++)
	{
		j[b] = '\0';
	}
	return (j);
}

#include "our_shell.h"
#include "our_shell.h"
/**
 *relloc - allocate the memory again
 *@point: void which allocate
 *@size_o: original size
 *@size_n: new size
 *Return: vpod pointer
 */
void *relloc(void *point, unsigned int size_o, unsigned int size_n)
{
	void *ptr;

	if (size_n == size_o)
		return (point);
	if (!size_n && point)
	{
		free(point);
		return (NULL);
	}
	ptr = malloc(size_n);
	if (ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (!point)
	{
		fillarr(ptr, '\0', size_n);
		free(point);
	}
	else
	{
		mycpymem(ptr, point, size_o);
		free(point);
	}
	return (ptr);
}
/**
 * arrfree - free memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void arrfree(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
/**
 * mycpymem - copy bytes of memory from source to destination
 *@dest: destination pointer
 *@src: source pointer
 *@n: size to be copied
 *Return: pointer to destination
 */
char *mycpymem(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * fillarr - fill an array by constant byte
 *@a: void pointer
 *@el: int
 *@len: length for int
 *Return: void pointer
 */
void *fillarr(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * mycal_oc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */
void *mycal_oc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}

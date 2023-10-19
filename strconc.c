#include "our_shell.h"

/**
 * helpfun -  newly concatinated allocated space in memory
 * @s1: first character pointer argument
 * @s2: second character pointer argument
 * Return: pointer character
 */
char *helpfun(char *s1, char *s2)
{
	unsigned int i, j, size, s1s, s2s;
	char *ptr;

	if (!(s1 && s2))
		return (NULL);
	for (i = 0; *(s1 + i) != '\0'; i++)
		;
	for (j = 0; *(s2 + j) != '\0'; j++)
		;
	s1s = i;
	s2s = j;
	size = s1s + s2s + 1;
	ptr = (char *)malloc(sizeof(char) * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < s1s; i++)
	{
		*(ptr + i) = *(s1 + i);
	}
	for (j = 0; s1s + j < size - 1; j++)
		*(ptr + s1s + j) = *(s2 + j);
	*(ptr + size - 1) = '\0';
	return (ptr);
}

/**
 * strconc -  newly concatinated allocated space in memory
 * @s1: first character pointer argument
 * @s2: second character pointer argument
 * Return: pointer character
 */
char *strconc(char *s1, char *s2)
{
	unsigned int i, j;
	char *ptr;

	if (s1 == NULL && s2 == NULL)
	{
		ptr = (char *) malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	else if (s1 == NULL)
	{
		for (i = 0; *(s2 + i) != '\0'; i++)
			;
		ptr = (char *) malloc(sizeof(char) * (i + 1));
		for (i = 0; *(s2 + i) != '\0'; i++)
			*(ptr + i) = *(s2 + i);
		*(ptr + i) = '\0';
		return (ptr);
	}
	else if (s2 == NULL)
	{
		for (j = 0; *(s1 + j) != '\0'; j++)
			;
		ptr = (char *) malloc(sizeof(char) * (j + 1));
		for (j = 0; *(s1 + j) != '\0'; j++)
			*(ptr + j) = *(s1 + j);
		*(ptr + j) = '\0';
		return (ptr);
	}
	ptr = helpfun(s1, s2);
	if (ptr == NULL)
	{
		free(s1);
		free(s2);
	}
	return (ptr);
}

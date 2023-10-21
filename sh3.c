#include "our_shell.h"
/**
 * mycmpstr - it compare the two string
 * @s1: first string
 * @s2: second string
 * Return: 0 if identical otherwise how much diffrent
 */
int mycmpstr(char *s1, char *s2)
{
	int cmp = 0, i, len1, len2;

	len1 = mylenstr(s1);
	len2 = mylenstr(s2);

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (len1 != len2)
		return (1);

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}
/**
 * myalphais - function to check if c is alphabet
 * @c: character to check
 * Return: 1 if true 0 if false
 */
int myalphais(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * myi_to_a - funciton that convert integer to character
 * @n: integer to convert
 * Return: character pointer
 */
char *myi_to_a(unsigned int n)
{
	int l = 0, i = 0;
	char *s;

	l = mylenint(n);
	s = malloc(l + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}
	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	s[i] = (n % 10) + '0';
	rev_arr(s, l);
	s[i + 1] = '\0';

	return (s);
}
/**
 * rev_arr - function reverse an array
 * @arr: string rev
 * @n: number of characr
 */
void rev_arr(char *arr, int n)
{
	int k;
	char t;

	for (k = 0; k < (n / 2); k++)
	{
		t = arr[k];
		arr[k] = arr[(n - 1) - k];
		arr[(n - 1) - k] = t;
	}
}
/**
 * mylenint - function that determine length of integer
 * @m: my total
 * Return: the status
 */
int mylenint(int m)
{
	int ml = 0;

	while (m != 0)
	{
		ml++;
		m /= 10;
	}
	return (ml);
}

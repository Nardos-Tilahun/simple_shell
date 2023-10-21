#include "our_shell.h"

/**
 * mycharput - character wirte
 * @ch: character
 * Return: return status
 */
int mycharput(char ch)
{
	return (write(1, &ch, 1));
}
/**
 * _myputs- to wirte a sting of character
 * @arr: strings
 */
void _myputs(char *arr)
{
	int k = 0;

	while (arr[k])
	{
		mycharput(k);
		k++;
	}
	mycharput('\n');
}
/**
 * cpystr -dupicate the charr array in stack
 * @first: first string
 * @second: second use of string
 * @limno: limited number
 * Return: new string
 */
char *cpystr(char *second, char *first, int limno)
{
	int j = 0;

	while (j < limno && *(first + j))
	{
		*(second + j) = *(first + j);
		j++;
	}
	while (j < limno)
	{
		*(second + j) = '\0';
		j++;
	}
	return (second);
}


/**
 * mylenstr - number of characters it store
 * @mystr: array of character
 * Return: character length
 */
int mylenstr(char *mystr)
{
	int k = 0;

	for (k  = 0; mystr[k] != '\0'; k++)
	{
		continue;
	}
	return (k);
}
/**
 * _atoi - function to convert string to a integer
 * @s: string input
 * Return: converted integer
 */
int _atoi(char *s)
{
	int i = 0, j = 1, k;
	unsigned int l = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			return (2);
		}
		k = s[i] - '0';

		if (l > 0 && !(k >= 0 && k <= 9))
			break;

		if (k >= 0 && k <= 9)
			l = l * 10 + k;

		i++;
	}
	l *= j;
	return (l);
}


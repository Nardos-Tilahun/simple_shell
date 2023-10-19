#include "our_shell.h"


/**
 * count_my_word - counting my word in a line
 * @each_line: - uses a line of string for counting a word
 * @dmeter: - delimeter that separate the string to count the words
 * Return: integer which count the word and return it
 */
int count_my_word(char *each_line, char *dmeter)
{
	char *each_word =  NULL, *temp_word = NULL;
	int word_count, idx, length;

	if (!each_line)
		return (0);
	for (idx = 0; each_line[idx] != '\0'; idx++)
		;
	length = idx;
	each_word = (char *)malloc(sizeof(char) * (idx + 1));
	if (each_word == NULL)
	{
		free(each_line);
		return (0);
	}
	for (idx = 0; idx < length ; idx++)
		each_word[idx] = each_line[idx];
	each_word[idx] = '\0';
	temp_word = strtokk(each_word, dmeter);
	if (temp_word == NULL)
	{
		free(each_line);
		free(each_word);
		return (0);
	}
	for (word_count = 0; temp_word != NULL; word_count++)
		temp_word = strtokk(NULL, dmeter);
	free(each_word);
	return (word_count);
}

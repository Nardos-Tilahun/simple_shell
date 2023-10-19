#include "our_shell.h"

/**
 * separate - separate each words from each line of the input
 * @each_line: uses a line of string of the command line
 *
 * Return: charcter pointer to pointer array of string
 */
char **separate(char *each_line)
{
	char **all_words;
	char *each_word;
	char dmeter[] = " \t\n";
	int count_word, idx, i;

	count_word = count_my_word(each_line, dmeter);
	if (count_word == 0)
		return (NULL);
	all_words = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (all_words == NULL)
	{
		free(each_line);
		return (NULL);
	}
	each_word = strtokk(each_line, dmeter);
	if (each_word == NULL)
	{
		free(each_line);
		return (NULL);
	}
	for (idx = 0; each_word != NULL; idx++)
	{
		all_words[idx] = copy_me(each_word);
		each_word = strtokk(NULL, dmeter);
	}
	all_words[idx] = NULL;
	if (idx != count_word)
	{
		for (i = 0; i < count_word; i++) {
			free(all_words[i]);
		}
		free(all_words);
	}
	free(each_line);
	return (all_words);
}

#include "our_shell.h"

/**
 * setup_and_initialize - Set up and initialize the program
 * @vector: The vector of arguments
 */
void setup_and_initialize(char **vector)
{
	if (vector[1] != NULL)
	{
		hit_file(vector[1], vector);
	}
	signal(SIGINT, signal_checker);
}

/**
 * execute_commands - Execute the main program logic
 * @vector: vector array
 * Return: The program's exit status
 */
int execute_commands(char **vector)
{
	char **com2, *user_input, **com;
	int c, i, check = 1, prostate = 0;

	for (c = 1; check; c++)
	{
		if (isatty(STDIN_FILENO))
			printing();
		user_input = catchline();
		if (user_input[0] == '\0')
			continue;
		myhist(user_input);
		com2 = splits(user_input);
		for (i = 0; com2[i]; i++)
		{
			com = chan_cmd(com2[i]);
			if (mycmpstr(com[0], "exit") == 0)
			{
				free(com2);
				exiting(com, user_input, vector, c, prostate);
			}
			else if (statbuilt(com) == 0)
			{
				prostate = checkinbuilt(com, prostate);
				free(com);
				continue;
			}
			else
				prostate = input_ch(com, user_input, c, vector);
			free(com);
		}
		free(user_input);
		free(com2);
		wait(&prostate);
	}
	return (prostate);
}

/**
 * main - Entry point
 * @size: Counter
 * @vector: Vector
 * Return: Returns status
 */
int main(__attribute__((unused)) int size, char **vector)
{
	int result;

	setup_and_initialize(vector);
	result = execute_commands(vector);
	return (result);
}


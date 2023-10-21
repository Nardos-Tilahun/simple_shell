#include "our_shell.h"

/**
 * hit_file - Reads commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */

void hit_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		warn_file(argv, count);
		exit(127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		catchfile(line, count, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * catchfile - Parse commands and handle their execution
 * @line: Line from file
 * @count: Error counter
 * @fp: File descriptor
 * @argv: Command line arguments
 */

void catchfile(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = chan_cmd(line);
	if (mycmpstrn(cmd[0], "exit", 4) == 0)
		filecheckext(cmd, line, fp);
	else if (statbuilt(cmd) == 0)
	{
		stat = checkinbuilt(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = input_ch(cmd, line, count, argv);
		free(cmd);
	}
}

/**
 * filecheckext - Exit status handler for file input
 * @line: Line from a file
 * @cmd: Parsed command
 * @fd: File Descriptor
 */

void filecheckext(char **cmd, char *line, FILE *fd)
{
	int status;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (myalphais(cmd[1][i++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}

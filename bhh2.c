#include "our_shell.h"
/**
 * myenvh - environ print
 */
void myenvh(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, mylenstr(msg));
}

/**
 * myenvseth - environ print
 */
void myenvseth(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "environment variable, or modifies an existing one.\n\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "\tUpon failure, prints a message to stderr.\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}

/**
 * help_unsetenv - environ print
 * 'unsetenv'
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "environmental variable.\n\n\tUpon failure, prints a ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "message to stderr.\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}
/**
 * herehelp - display help for builtin commands
 * @cmd: parsed command
 * @st: Status of last command executed
 * Return: 0 Success
 */
int herehelp(char **cmd, __attribute__((unused))int st)
{
	if (!cmd[1])
		joy();
	else if (mycmpstr(cmd[1], "alias") == 0)
		alhi();
	else if (mycmpstr(cmd[1], "cd") == 0)
		cdh();
	else if (mycmpstr(cmd[1], "exit") == 0)
		exh();
	else if (mycmpstr(cmd[1], "env") == 0)
		myenvh();
	else if (mycmpstr(cmd[1], "setenv") == 0)
		myenvseth();
	else if (mycmpstr(cmd[1], "unsetenv") == 0)
		help_unsetenv();
	else if (mycmpstr(cmd[1], "help") == 0)
		helper();
	return (0);
}

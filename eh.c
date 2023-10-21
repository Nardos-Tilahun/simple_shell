#include "our_shell.h"

/**
 * show_err - show error
 * @input: input from keyboard
 * @counter: count the number if shell
 * @argv: Arguments
 */

void show_err(char *input, int counter, char **argv)
{
	char *er;

	myprinter(argv[0]);
	myprinter(": ");
	er = myi_to_a(counter);
	myprinter(er);
	free(er);
	myprinter(": ");
	myprinter(input);
	myprinter(": not found\n");
}

/**
 *  errpre - display error
 * @argv: Arguments
 * @c: Counting mistakes
 * @cmd: changed command array
 */

void errpre(char **argv, int c, char **cmd)
{
	char *er = myi_to_a(c);

	myprinter(argv[0]);
	myprinter(": ");
	myprinter(er);
	myprinter(": ");
	myprinter(cmd[0]);
	myprinter(": Illegal number: ");
	myprinter(cmd[1]);
	myprinter("\n");
	free(er);
}

/**
 * warn_file - Prints
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Error Count
 */

void warn_file(char **argv, int c)
{
	char *er = myi_to_a(c);

	myprinter(argv[0]);
	myprinter(": ");
	myprinter(er);
	myprinter(": Can't open ");
	myprinter(argv[1]);
	myprinter("\n");
	free(er);
}


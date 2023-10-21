#include "our_shell.h"

/**
 * show_err - Displays error message
 * @input: Input recieved from user
 * @counter: Count of shell loop
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
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
 *  errpre - Prints custom Error
 * @argv: Arguments before program starts(argv[0] == Shell Program Name)
 * @c: Error Count
 * @cmd: Array of parsed command strings
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
 * warn_file - Prints custom Error
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


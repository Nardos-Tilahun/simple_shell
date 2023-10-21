#include "our_shell.h"
/**
 * joy - Displays all possible builtin shellby commands
 */
void joy(void)
{
	char *msg = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "Type 'help' to see this list.\nType 'help name' to find ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "out more about the function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}

/**
 * alhi - Displays information on the shell by builtin command 'alias'
 */
void alhi(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "\n\talias: Prints a list of all aliases, one per line, in ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "the format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = " the aliases name, name2, etc. one per line, in the ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Defines";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = " an alias for each NAME whose VALUE is given. If NAME ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "is already an alias, replace its value with VALUE.\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}

/**
 * cdh - Displays information on the shell by builtin command 'cd'
 */
void cdh(void)
{
	char *msg = "cd: cd [DIRECTORY]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = " process to DIRECTORY.\n\n\tIf no argument is given, the ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "command is interpreted as cd $HOME. If the argument '-' is";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = " given, the command is interpreted as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "\tThe environment variables PWD and OLDPWD are updated ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "after a change of directory.\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}

/**
 * exh - Displays information on the shell by builtin command 'exit'
 */
void exh(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n\n\tThe ";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "STATUS argument is the integer used to exit the shell.";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = " If no argument is given, the command is interpreted as";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = " exit 0.\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}

/**
 * helper - Displays information on the shell by builtin command 'help'
 */
void helper(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "\n      help [BUILTIN NAME]\n\tSee specific information on each ";
	write(STDOUT_FILENO, msg, mylenstr(msg));
	msg = "builtin command.\n";
	write(STDOUT_FILENO, msg, mylenstr(msg));
}


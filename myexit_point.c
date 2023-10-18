#include "our_shell.h"

/**
 * myexit_point - close the parent when signal sent from child
 * @check: the checker to check if it is signal
 */
void myexit_point(int check)
{
	if (check == SIGUSR1)
		exit(0);
}

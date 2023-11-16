#include "shell.h"

/**
 * exitt - Implementation of the 'exit' built-in command.
 * @arv: Array of arguments.
 *
 * This function handles the 'exit' command, performing any necessary cleanup
 * and exiting the program.
 */

void exitt(char **arv)

{
	(void)arv;
	exit(0);
}


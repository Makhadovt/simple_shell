#include "shell.h"
/**
 * _getline_cmd -  gets input commands
 * Return: The inputs.
 */

char *_getline_cmd(void)
{
	char *cmd_line = NULL;
	size_t character_usr = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&cmd_line, &character_usr, stdin) == -1)
	{
		free(cmd_line);
		return (NULL);
	}

	return (cmd_line);
}

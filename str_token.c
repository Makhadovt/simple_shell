#include "shell.h"
/**
 * tokenizer - tokenizers a stirng
 * @cmd_line: what the user inputsed
 * Return: a ptr to arr of ptrs
 */

char **tokenizer(char *cmd_line)
{
	char **user_command = NULL;
	char *token = NULL;
	size_t i = 0;
	int size = 0;

	if (cmd_line == NULL)
		return (NULL);

	for (i = 0; cmd_line[i]; i++)
	{
		if (cmd_line[i] == ' ')
			size++;
	}
	if ((size + 1) == _strlen(cmd_line))
		return (NULL);
	user_command = malloc(sizeof(char *) * (size + 2));
	if (user_command == NULL)
		return (NULL);

	token = strtok(cmd_line, " \n\t\r");

	for (i = 0; token != NULL; i++)
	{
		user_command[i] = token;
		token = strtok(NULL, " \n\t\r");
	}
	user_command[i] = NULL;
	return (user_command);
}

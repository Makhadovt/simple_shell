#include "shell.h"
/**
 * main - Main arguments functions
 * @ac: Count of argumnents
 * @av: Arguments
 * @env: Environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	int valueue = 0, status = 0, is_path = 0;
	char *line = NULL, /**ptr to input_cmd*/ **commands = NULL; /**tokenizerd commands*/
	(void)ac;
	while (1)/* loop until exit */
	{
		errno = 0;
		line = _getline_cmd();/** reads user inputs*/
		if (line == NULL && errno == 0)
			return (0);
		if (line)
		{
			valueue++;
			commands = tokenizer(line);/** tokenizers or parse user inputs*/
			if (!commands)
				free(line);
			if (!_strcmp(commands[0], "env"))/**checks if user wrote env"*/
				_getenv(env);
			else
			{
				is_path = info_path(&commands[0], env);/** tokenizers PATH*/
				status = exec_fork(commands, av, env, line, valueue, is_path);
					if (status == 200)
					{
						free(line);
						return (0);
					}
				if (is_path == 0)
					free(commands[0]);
			}
			free(commands); /*free up memory*/
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);/** Writes to standard output*/
			exit(status);
		}
		free(line);
	}
	return (status);
}

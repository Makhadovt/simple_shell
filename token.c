#include "shell.h"
/**
 * info_path - Separate the path in new strings.
 * @arg: Command inputs of user.
 * @env: Enviroment.
 * Return: Pointer to strings.
 */
int info_path(char **arg, char **env)
{
	char *token = NULL, *con_path = NULL, *absolute_path = NULL;
	size_t v_path, len;
	struct stat scl;

	if (stat(*arg, &scl) == 0)
		return (-1);
	con_path = find_path(env);/** gets the content of "PATH="*/
	if (!con_path)
		return (-1);
	token = strtok(con_path, ":"); /**tokenizers the content of "PATH="*/
	len = _strlen(*arg); /**gets length of arg*/
	while (token)
	{
		v_path = _strlen(token);
		absolute_path = malloc(sizeof(char) * (v_path + len + 2));
		if (!absolute_path)
		{
			free(con_path);
			return (-1);
		}
		absolute_path = strcpy(absolute_path, token);
		_strcat(absolute_path, "/");
		_strcat(absolute_path, *arg);

		if (stat(absolute_path, &scl) == 0)
		{
			*arg = absolute_path;
			free(con_path);
			return (0);
		}
		free(absolute_path);
		token = strtok(NULL, ":");
	}
	token = '\0';
	free(con_path);
	return (-1);
}

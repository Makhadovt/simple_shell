#include "shell.h"
int exec_cd(char **args);
int exec_help(char **args);
int exec_exit(char **args);
int exec_ld(char **args);

/*
 * List of builtin commands, followed by their corresponding functions.
 */
char *builtin_s[] = {"cd", "help", "exit", "^D"};

int (*builtin_f[]) (char **) = {&exec_cd, &exec_help, &exec_exit, &exec_ld};

/**
 * built_ins - size
 * Return: size
 */

int built_ins(void)
{
	return (sizeof(builtin_s) / sizeof(char *));
}

/*
 * Builtin function implementations.
*/

/**
 * exec_cd - builtin to change dirs
 * @args: List of args.  args[0] is "cd".  args[1] is the directory.
 * Return: 1 on success
 */
int exec_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * exec_help - prints the help for the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 1, to continue executing.
 */
int exec_help(char **args)
{
	int i;

	printf("trace tracy\n");
	printf("Feel free to ask anything\n");
	(void)args;
	for (i = 0; i < built_ins(); i++)
	{
		printf("  %s\n", builtin_s[i]);
	}

	return (1);
}

/**
 * exec_exit - builtin to exit the shell
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int exec_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * exec_ld - builtin to handle "^D" call
 * @args: List of args.  Not examined.
 * Return: Always returns 0, to terminate execution.
 */
int exec_ld(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 *exec_fork - foo that create a fork.
 *@arg: Command and valueues path.
 *@av: Has the name of our program.
 *@env: Environment
 *@cmd_line: Command line for the user.
 *@n_pid: ID of proces.
 *@c: Checker add new test
 *Return: 0 success
 */

int exec_fork(char **arg, char **av, char **env, char *cmd_line, int n_pid, int c)
{

	pid_t child;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < built_ins(); i++)
	{
		if (_strcmp(arg[0], builtin_s[i]) == 0)
			return (builtin_f[i](arg));
	}
	child = fork();
	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], n_pid, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(cmd_line);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}

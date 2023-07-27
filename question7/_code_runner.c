#include "main.h"
/**
 * _executor - Executes a command or a series of commands
 * @array: An array of command line arguments
 * @argv: An array of arguments passed to the main program
 * @cmdnum: The command number in the array of command line arguments
 * @st: A pointer to a stat structure (used to check
 * file permissions before execution)
 * Return: Integer indicating the status of execution
 */
int _executor(char **array, char **argv, int cmdnum, struct stat *st)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		free(st);
		free_array(array);
		return (0);
	}
	if (child_pid == 0)
	{
		if (execve(array[0], array, environ) == -1)
		{
			free(st);
			_print_f("%s: %d: %s: not found\n", argv[0], cmdnum, array[0]);
			free_array(array);
			_exit(-1);
		}
	}
	else
	{
	while (waitpid(-1, &status, 0) != child_pid)
		;
	}
if (status == 0)
	errno = 0;
if (status == 512)
	errno = 2;
if (status == 65280)
	errno = 127;
return (errno);
}

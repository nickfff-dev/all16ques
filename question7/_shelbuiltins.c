#include "main.h"

/**
* _handle_shell_inbuilt - the function name
* @line: parameter of type char *.
* @array: parameter of type char **.
* @argv: aparameter of type char **
* @env: environment copy
* Return: int .
*/
int _handle_shell_inbuilt(char *line, char **array,
		char **argv, Environment *env)
{
	int isArg = 0, exit_status = 0, i, chck_unset = 0;

	if (_str_cmp(array[0], "exit") == 0)
	{
		if (array[1] != NULL)
		{
			isArg = _handle_exit(array);
			if (isArg == 1)
			{
				_print_f("%s: %d: exit: Illegal number: %s\n", argv[0], 1, array[1]);
				exit(2);
			}
			i = 0;
			while (array[1][i] != '\0')
			{
				exit_status = (exit_status * 10) + (array[1][i] - '0');
				i++;
			}
		}
		free_array(array);
		free(line);
		if (chck_unset == 1)
		{
			free_my_environ(env);
		}
		exit(exit_status);
	}
	if (_str_cmp(array[0], "env") == 0)
	{
		print_environment(env);
		return (2);
	}
	if (_str_cmp(array[0], "setenv") == 0)
	{
		if (array[1] == NULL || array[2] == NULL)
		{
			_print_f("setenv: usage: setenv VARIABLE VALUE\n");
			return (2);
		}
		chck_unset = 1;
		my_setenv(array[1], array[2], env);
return (2);
	}
	if (_str_cmp(array[0], "unsetenv") == 0)
	{
		if (array[1] == NULL)
		{
			_print_f("unsetenv: usage: unsetenv VARIABLE\n");
			return (2);
		}
		my_unsetenv(array[1], env);
return (2);
	}
	return (0);
}
/**
* _handle_exit - Free allocated memory and terminate the shell.
* @array: An array of command line arguments.
* Return: int
*/
int _handle_exit(char **array)
{
	if (digit_checker(array[1]) != 0)
	{
		return (1);
	}
	return (0);
}

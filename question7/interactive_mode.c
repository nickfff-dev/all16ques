#include "main.h"

/**
* interactive_mode - the function name
* @argv: parameter of type char **.
* Return: int .
*/
int interactive_mode(char **argv, Environment *env)
{
	char *line = NULL;
	size_t str_len = BUFF_SIZE;
	ssize_t x;
	int tokencount = 0, cmdnum = 1, status = 0;

	while (1)
	{
		write(1, "$ ", 2);
		tokencount = 0;
		x = my_getline(&line, &str_len, STDIN_FILENO);
		if (x < 0)
		{
			write(1, "\n", 1);
			free(line);
			break;
		}
		tokencount = _count_token(line);
		status = handle_line(line, tokencount, argv, cmdnum, env);
		cmdnum++;
		free(line);
		line = NULL;
		str_len = BUFF_SIZE;
	}
	return (status);
}

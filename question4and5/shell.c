#include "main.h"
/**
* main - The entry point of the program
* @argc: parameter of type int .
* @argv: parameter of type char **.
* Return: int .
*/
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t str_len = 0;
	int is_interactivemode, status, tokencount = 0, x, y, cmdnum = 1;

	is_interactivemode = isatty(STDIN_FILENO);
	if (is_interactivemode == 0 && argc == 1)
	{
		while ((y = getline(&line, &str_len, stdin)) > 0)
		{
			tokencount = _count_token(line);
			status = handle_line(line, tokencount, argv, cmdnum);
			line = NULL;
			if (status != 0)
			{
				free(line);
				exit(status);
			}
		}
		free(line);
		return (status);
	}
	while (is_interactivemode)
	{
		write(1, "$ ", 2);
		tokencount = 0;
		x = getline(&line, &str_len, stdin);
		if (x < 0)
		{
			free(line);
			write(1, "\n", 1);
			break;
		}
		tokencount = _count_token(line);
		handle_line(line, tokencount, argv, cmdnum);
		cmdnum++;
		line = NULL;
		free(line);
	}
	return (0);
}
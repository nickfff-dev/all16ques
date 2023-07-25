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
	size_t str_len = BUFF_SIZE;
	ssize_t x, y;
	int is_interactivemode, status, tokencount = 0,  cmdnum = 1;

	status = 0;
	is_interactivemode = isatty(STDIN_FILENO);
	if (is_interactivemode == 0 && argc == 1)
	{
		while ((y = my_getline(&line, &str_len, STDIN_FILENO)) > 0)
		{
			tokencount = _count_token(line);
			status = handle_line(line, tokencount, argv, cmdnum);
			
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
		x = my_getline(&line, &str_len, STDIN_FILENO);
		if (x < 0)
		{
			write(1, "\n", 1);
			free(line); 
			break;
		}
		tokencount = _count_token(line);
		status = handle_line(line, tokencount, argv, cmdnum);
		cmdnum++;
		free(line);  
		line = NULL; 
		str_len = BUFF_SIZE; 
	}
	return (EXIT_SUCCESS);
}

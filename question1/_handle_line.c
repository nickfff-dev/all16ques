#include "main.h"
/**
* handle_line - the function name
* @line: parameter of type char *.
* @num_tokens: parameter of type int .
* @argv: parameter of type char **.
* @cmdnum: parameter of type int .
* Return: int .
*/
int handle_line(char *line, int num_tokens, char **argv, int cmdnum)
{
	char **array = NULL, **array2 = NULL;
	int status = 0, x;
	size_t str_len = 0;

	array2 = create_array_from_line(line, num_tokens, array);
	if (array2 == NULL)
	{
		return (1);
	}
	for (x = 0; array2[x] != NULL; x++)
	{
		if (array2[x][0] == '-' || array2[x][0] == '~' || array2[x][0] == '.')
		{
			str_len = _strlen(line);
			line[str_len - 1] = '\0';
			_print_f("%s: %d: %s: No such file or directory\n",
			argv[0], cmdnum, line);
			free(line);
			free_array(array2);
			return (1);
		}
	}
	status = execute_external_command(line, array2, argv, cmdnum);
	free(line);
	free(array);
	free_array(array2);
	return (status);
}

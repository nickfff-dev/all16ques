#include "main.h"
/**
* main - The entry point of the program
* @argc: parameter of type int .
* @argv: parameter of type char **.
* Return: int .
*/


int main(int argc, char **argv)
{
	int is_interactivemode, retun_val;
	Environment env;

	copy_environ(&env);
	is_interactivemode = isatty(STDIN_FILENO);
	if (is_interactivemode == 0 && argc == 1)
	{
		return (non_interactive_mode(argv, &env));
	}
	retun_val = interactive_mode(argv, &env);
	free_my_environ(&env);
	return (retun_val);

}

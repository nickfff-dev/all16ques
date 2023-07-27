#include "main.h"

/**
* digit_checker - Checks if a string is composed of digits
* @arg: The string to check for digits
* Return: Integer value stating the result of the check
*/
int digit_checker(char *arg)
{
	int i = 0;

	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

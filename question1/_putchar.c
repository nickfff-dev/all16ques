#include "main.h"

/**
* _putchar - the function name
* @c: parameter of type char .
* Return: int .
*/
int _putchar(char c)
{
	return (write(2, &c, 1));
}

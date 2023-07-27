#include "main.h"
/**
* my_stritk - Tokenizes a string by a delimiter
* @str: The string to tokenize
* @delim: The delimiter by which to split the string
* Return: Pointer to the start of the next token
*/
char *my_stritk(char *str, const char *delim)
{
	static char *src;
	char *p, *ret = 0;

	if (str != NULL)
	{
		src = str;
	}
	if (src == NULL)
	{
		return (NULL);
	}
	p = strpbrk(src, delim);
	if (p != NULL)
	{
		*p  = 0;
		ret = src;
		src = ++p;
	}
	else if (*src)
	{
		ret = src;
		src = NULL;
	}
	return (ret);
}

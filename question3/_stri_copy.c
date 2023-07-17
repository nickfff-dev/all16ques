#include "main.h"

/**
  * _strcpy - function that copies the string pointed to by src,
  * @dest: parameter of type char *.
  * @src: parameter of type char *.
  * Return: char *.
 */

char *_str_cpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return (dest);
}
#include "main.h"
char *my_stritk(char *str, const char *delim)
{
    static char *src = NULL;
    char  *p,  *ret = 0;

    if (str != NULL)
        src = str;

    if (src == NULL)
        return NULL;

    if ((p = strpbrk(src, delim)) != NULL) 
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

    return ret;
}

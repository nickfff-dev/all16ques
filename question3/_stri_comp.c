#include "main.h"

int _str_cmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] || s2[i])
    {
        if (s1[i] == s2[i])
        {
            s1++;
			s2++;
        }
        else
			return (-1);
    }
    return (0); 
}
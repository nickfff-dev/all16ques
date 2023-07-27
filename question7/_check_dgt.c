#include "main.h"


int digit_checker(char *arg) 
{
    int i = 0;
    while(arg[i] != '\0')
    {
        if(arg[i] < '0' || arg[i] > '9')
        {
            return (1); 
        }
        i++;
    }
    return (0);
}
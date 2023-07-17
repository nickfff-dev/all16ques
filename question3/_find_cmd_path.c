#include "main.h"


int _look_in_path(char *str, char **tokens)
{
    struct dirent *fldr;
    int dest = 0, isOnPath = -1;

    str = strtok(str, ":");
    while (str != NULL  && isOnPath != 1)
    {
        DIR *fldr = opendir(str);
        if (fldr == NULL)
        {
           return (0);
        }
        while ((fldr = readdir(fldr)) != NULL)
        {
            if (_str_cmp(fldr->d_name, tokens[0]) == 0)
            {
                
                _run_path_command(str, tokens);
                isOnPath = 0;
                dest = 1;
                break;
            }
        }
        closedir(fldr);
        if(dest == 0)
            str = strtok(NULL, ":");
    }
    return (isOnPath);
}
#include "main.h"


int _look_in_path(char *str, char **tokens)
{
    struct dirent *fldr;
    DIR *mydir;
    int dest = 0, isOnPath = -1;

    str = strtok(str, ":");
    while (str != NULL  && isOnPath != 1)
    {
        mydir = opendir(str);
        if (mydir == NULL)
        {
           return (0);
        }
        while ((fldr = readdir(mydir)) != NULL)
        {
            if (_str_cmp(fldr->d_name, tokens[0]) == 0)
            {
                
                _run_path_command(str, tokens);
                isOnPath = 0;
                dest = 1;
                break;
            }
        }
        closedir(mydir);
        if(dest == 0)
            str = strtok(NULL, ":");
    }
    return (isOnPath);
}
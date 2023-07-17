#include "main.h"

void _run_path_command(char *s, char **tokens)
{
    int status, x, y;
	pid_t child_pid;
	char *pthstr = NULL;

    for (x = 0; *(s + x) != '\0'; x++)
        ;
    for (y = 0; tokens[0][y] != '\0'; y++)
        ;
    pthstr = malloc(sizeof(char) * (x + y + 2));
    if (pthstr == NULL)
    {
        perror("Error: ");
        exit(1);
    }
    _str_cpy(pthstr, s);
    _str_cat(pthstr, "/");
    _str_cat(pthstr, *tokens);
    pthstr[x + y + 1] = '\0';
    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error: ");
        exit(1);
    }
    if (child_pid == 0)
    {
        if(access(pthstr    , X_OK) == 0)
        {
            execve(pthstr, tokens, environ);
        } 
    }
    else
    {
       while (waitpid(-1, &status, 0) !=  child_pid)
            ;
    }
    if (status == 0)
        errno = 0;
    free(pthstr);
}
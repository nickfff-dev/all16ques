#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <limits.h>
#include <dirent.h>
#include <stdarg.h>
#include <errno.h>

extern char **environ;
/**
* struct format - types of data and their function
* @ptr: the type of data
* @type: pointer to function for type
*/
typedef struct format
{
	char *ptr;
	int (*type)();

} format;
int _putchar(char c);
int _strlen(char *s);
int _print_f(const char *frmt, ...);
int _count_token(char *line);
int _pr_str(va_list *args);
char *_strdup(char *str);
void free_array(char **array);
int _prt_dgt(va_list *args);
int _check_frmt(va_list *args, const char *frmt, int x);
char **create_array_from_line(char *line, int num_tokens, char **array);
void _get_digts(int x);
int execute_external_command(char *line, char **array,
char **argv, int cmdnum);
int handle_line(char *line, int num_tokens, char **argv, int cmdnum);
int _executor(char *line, char **array, char **argv,
int cmdnum, struct stat *st);
#endif

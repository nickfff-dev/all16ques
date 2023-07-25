#include "main.h"



 
 ssize_t my_getline(char **lineptr, size_t *n, int fd) 
 {     
     static char buffer[BUFF_SIZE];
     static ssize_t read_chars = 0;
     static ssize_t total_chars = 0;
     size_t i = 0;

     if (lineptr == NULL || n == NULL) 
        return -1;
     if (*lineptr == NULL) 
     {
         *n = BUFF_SIZE;
         *lineptr = malloc(*n);
         if (*lineptr == NULL) 
            return -1;
     }
     while (1) 
     {
         if (total_chars == read_chars)
         {
             total_chars = read(fd, buffer, BUFF_SIZE);
             if (total_chars == 0)
                return -1;
             else if (total_chars < 0) 
                return -1;
             read_chars = 0;
         }
         for (i = 0; read_chars < total_chars; i++, read_chars++)
         {
             (*lineptr)[i] = buffer[read_chars];
             if (buffer[read_chars] == '\n')
             {
                 read_chars++;
                 (*lineptr)[i+1] = '\0';
                 *n = i+1;
                 return *n;
             }
         }
     }
 }


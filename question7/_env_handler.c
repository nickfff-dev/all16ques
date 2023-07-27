#include "main.h"



void copy_environ(Environment *env) {
    int i;
    for (i = 0; environ[i] != NULL; i++);
    env->alloc_len = i;
    env->my_environ = malloc(sizeof(char *) * (env->alloc_len + 1));

    for (i = 0; environ[i] != NULL; i++)
        env->my_environ[i] = strdup(environ[i]);

    env->my_environ[i] = NULL;
}

void my_setenv(char *name, char *value, Environment *env) {
    int i;
    char *new_entry = malloc(strlen(name) + strlen(value) + 2);
    sprintf(new_entry, "%s=%s", name, value);

    for (i = 0; env->my_environ[i] != NULL; i++) {
        if (strncmp(env->my_environ[i], name, strlen(name)) == 0 && (env->my_environ[i])[strlen(name)] == '=') {
            free(env->my_environ[i]);
            env->my_environ[i] = new_entry;
            return;
        }
    }

    if (env->alloc_len <= i + 2) {  
        env->alloc_len *= 2;
        env->my_environ = realloc(env->my_environ, sizeof(char *) * env->alloc_len);  
    }
    env->my_environ[i] = new_entry;
    env->my_environ[i + 1] = NULL; 
}

void my_unsetenv(char *name, Environment *env) {
    int i, shift = 0;
    for (i = 0; env->my_environ[i] != NULL; i++) {
        if (shift) {
            env->my_environ[i - 1] = env->my_environ[i];
        } 
        else if (strncmp(env->my_environ[i], name, strlen(name)) == 0 && (env->my_environ[i])[strlen(name)] == '=') {
            free(env->my_environ[i]);
            shift = 1;
        }
    }
    if (shift)
        env->my_environ[i - 1] = NULL;
}


void free_my_environ(Environment *env) {
    int i;
    for (i = 0; env->my_environ[i] != NULL; i++)
        free(env->my_environ[i]);

    free(env->my_environ);
    env->my_environ = NULL;
    env->alloc_len = 0;
}


void print_environment(Environment *env)
{
    int i;
    for (i = 0; env->my_environ[i] != NULL; i++) 
    {
        _puts_stri(env->my_environ[i]);
        _puts_stri("\n");
    }
}
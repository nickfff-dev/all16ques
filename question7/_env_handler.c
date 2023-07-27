#include "main.h"

/**
* copy_environ - Copies the environment into our structure
* @env: Pointer to our self-defined environment structure.
* Return: void
*/
void copy_environ(Environment *env)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	;
	env->alloc_len = i;
	env->my_environ = malloc(sizeof(char *) * (env->alloc_len + 1));
	for (i = 0; environ[i] != NULL; i++)
	env->my_environ[i] = strdup(environ[i]);
	env->my_environ[i] = NULL;
}
/**
* my_setenv - Sets an environment variable
* @name: type char
* @value: type char
* @env: environment copy
* Return: void
*/
void my_setenv(char *name, char *value, Environment *env)
{
	int i;
	char *new_entry = malloc(strlen(name) + strlen(value) + 2);

	sprintf(new_entry, "%s=%s", name, value);
	for (i = 0; env->my_environ[i] != NULL; i++)
	{
		if (strncmp(env->my_environ[i], name, strlen(name)) == 0 &&
				(env->my_environ[i])[strlen(name)] == '=')
		{
			free(env->my_environ[i]);
			env->my_environ[i] = new_entry;
			return;
		}
	}
	if (env->alloc_len <= i + 2)
	{
		env->alloc_len *= 2;
		env->my_environ = realloc(env->my_environ,
				sizeof(char *) * env->alloc_len);
	}
	env->my_environ[i] = new_entry;
	env->my_environ[i + 1] = NULL;
}



/**
* my_unsetenv - Unsets an environment variable
* @name: type char
* @env: environment copy
* Return: void
*/
void my_unsetenv(char *name, Environment *env)
{
	int i, shift = 0;

	for (i = 0; env->my_environ[i] != NULL; i++)
	{
		if (shift)
		{
			env->my_environ[i - 1] = env->my_environ[i];
		}
		else if (strncmp(env->my_environ[i], name, strlen(name)) == 0
				&& (env->my_environ[i])[strlen(name)] == '=')
		{
			free(env->my_environ[i]);
			shift = 1;
		}
	}
}
/**
* free_my_environ - Frees the stored environment
* @env: environement copy
* Return: void
*/
void free_my_environ(Environment *env)
{
	int i;

	for (i = 0; env->my_environ[i] != NULL; i++)
	free(env->my_environ[i]);
	free(env->my_environ);
	env->my_environ = NULL;
	env->alloc_len = 0;
}
/**
* print_environment - Prints out the environment
* @env: environment copy
* Return: void
*/
void print_environment(Environment *env)
{
	int i;

	for (i = 0; env->my_environ[i] != NULL; i++)
	{
		_puts_stri(env->my_environ[i]);
		_puts_stri("\n");
	}
}

#include "shell.h"

/**
 * checking_path -function that checking the path
 * @env: environtmen
 * @argvs: vector args
 * Return: return -1
 */
int checking_path(char **env, char **argvs)
{
	int i;
	char *path;
	char **paths;

	paths = get_path(env);

	if (paths == NULL || argvs == NULL)
		return (-1);

	i = 0;
	while (paths[i] != NULL)
	{
		path = str_concat(paths[i], argvs[0]);
		if (access(path, F_OK & X_OK & R_OK) == 0)
		{
			free(argvs[0]);
			printf("%s", path);
			*(argvs) = path;
			free_ptr(paths);
			return (0);
		}
		free(path);
		i++;
	}

	free_ptr(paths);
	return (access(argvs[0], F_OK & X_OK & R_OK));
}


/**
 * chr_del - count how many character have delimiter *ptr
 * @str: string
 * @delim: char to find in str
 * Return: - int number
 */

int chr_del(char *str, char *delim)
{
	int result = 0, i, j;

	if (str != NULL && delim != NULL)
	{
		i = 0;
		while(delim[i] != '\0')
			i++;
		j = 0;
		while (str[j] != '\0')
			j++;
		if (delim[i] == str[j])
			result++;
	}
	return (result);
}

/**
 * get_path - get the PATH in the environment
 * @env: enviroment var
 * Return: double ponter with each route in the path.
 */
char **get_path(char **env)
{
	char *str = "PATH", *my_path, *aux, **paths;
	unsigned int i = 0, j = 0, size;

	if (env == NULL)
		return (NULL);


	while (env[i] != NULL)
	{
		aux = _strstr(env[i], str);
		if (aux != NULL)
		{
			aux = _strdup(aux);
			size = chr_del(aux, DELIM_PATH) + BUF_SIZE;
			paths = (char **)malloc(sizeof(char *) * size);

			if (paths == NULL)
				return (NULL);

			my_path = strtok(aux, DELIM_PATH);
			while (my_path != NULL)
			{

				paths[j] = _strdup(my_path);
				if (paths[j] == NULL)
				{
					free(aux);
					return (free_ptr(paths));
				}
				j++;
				my_path = strtok(NULL, DELIM_PATH);
			}
			paths[j] = NULL;
			free(aux);
			return (paths);
		}
		i++;
	}
	return (NULL);
}


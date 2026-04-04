
#include "../libft.h"

char	**malloc_strcpy_array(char **origin)
{
	size_t	i;
	size_t	len;
	char	**array;

	len = col_count(origin);
	array = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (origin[i])
	{
		array[i] = malloc_strcpy(origin[i]);
		i++;
	}
	array[i] = 0;
	return (array);
}

size_t	col_count(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

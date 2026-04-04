#include "../minishell.h"

int	len_array(char **array)
{
	int	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
	{
		i++;
	}
	return (i);
}


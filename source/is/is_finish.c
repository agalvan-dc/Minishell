#include "minishell.h"

int		is_finish(char c)
{
	if (c == '\0')
		return (1);
	return (0);
}

int		index_is_overflow(char *s, int i)
{
	if (i >= ft_strlen(s))
		return (1);
	return (0);
}

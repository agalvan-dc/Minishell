#include "../minishell.h"

int		is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

int		is_single_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int		is_quote(char c)
{
	if (is_double_quote(c) || is_single_quote(c))
		return (1);
	return (0);
}

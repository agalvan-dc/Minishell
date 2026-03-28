#include "../minishell.h"

int		is_arg(char *s, int i)
{
	if (!(is_separator(s, i)) && !(is_blank(s[i])))
		return (1);
	return (0);
}

int		is_flags(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (s[i] == '-' && s[i + 1] == 'n')
		return (1);
	return (0);
}

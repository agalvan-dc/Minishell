#include "../../minishell.h"

int		line_is_finish(char *s, int i)
{
	if (i >= ft_strlen(s))
		return (1);
	return (0);
}

int		line_is_empty(char *s)
{
	if (!s || s[0] == '\0')
		return (1);
	return (0);
}

int		is_dollar_word(t_env *env, char *s, int i)
{
	if (s[i] == '$' && is_arg_sep(env, s, i))
		return (1);
	return (0);
}

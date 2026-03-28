#include "../minishell.h"

int		is_not_null(char s, char c)
{
	if (s && c)
		return (1);
	return (0);
}

int		is_null(char *s)
{
	if (!s)
		return (1);
	return (0);
}

int		is_value_null(char *s)
{
	if (s[0] == '\0')
		return (1);
	return (0);
}

int		is_word(t_env *env, char *s, int i)
{
	if (!(is_blank(s[i])) && !(is_quote(s[i])) && !(is_separator(s[i])) && !(is_variable(env, s, i)))
		return (1);
	if (is_dollar_word(env, s, i))
		return (1);
	return (0);
}

int		is_backslash(char c)
{
	if (c == '\\')
		return (1);
	return (0);
}

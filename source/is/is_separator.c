#include "../minishell.h"

int		is_separator(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (is_redirection(s, i) || is_blank_before_finish(s, i))
		return (1);
	return (0);
}

int		is_delimiter(t_env *env, char *s, int i)
{
	if (is_blank(s[i]) || is_separator(s, i) || is_variable(s, i))
		return (1);
	return (0);
}

int		is_var_delimiter(char *s, int i)
{
	if (is_blank(s[i]) || is_separator(s, i) || s[i] == '$' 
	|| is_finish(s, i) || is_quote(s[i]))
		return (1);
	return (0);
}

int		is_arg_sep(t_env *env, char *s, int i)
{
	if (is_separator(s, i) || is_variable(s, i))
		return (1);
	return (0);
}

int		is_word_arg_sep(t_env *env, char *s, int i)
{
	if (is_arg_sep(env, s, i) || is_quote(s[i]) || is_blank(s[i]))
		return (1);
	return (0);
}

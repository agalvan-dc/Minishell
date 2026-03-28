#include "../minishell.h"

int		is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		is_blank_arg(t_env *env, char *s, int i)
{
	if (is_blank(s[i]) && !(is_blank(s[i + 1])) 
		&& !(is_separator(s, i + 1)) && !(is_variable(env, s, i)) 
		&& s[i] != '$' && !(is_finish(s[i + 1])))
		return (1);
	return (0);
}

int		is_blank_before_redir(char *s, int i)
{
	if (is_blank(c) && is_separator(s, i + 1))
	{
		while (s[i] && is_blank(s[i]))
		{
			if (is_redirection(s, i + 1))
				return (1);
			i++;
		}
	}
	return (0);
}

int		is_blank_before_finish(char *s, int i)
{
	if (is_blank(s[i]))
	{
		while (s[i] && is_blank(s[i]))
		{
			if (is_finish(s[i + 1]))
				return (1);
			i++;
		}
	}
	return (0);
}

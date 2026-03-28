#include "../minishell.h"

int		is_output_chevron(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (s[i] == '>' && s[i + 1] != '>')
		return (1);
	return (0);
}

int		is_input_chevron(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (s[i] == '<' && s[i + 1] != '<')
		return (1);
	return (0);
}

int		is_append_chevron(char *s, int i)
{
	if (index_is_overflow(s,i))
		return (0);
	if (s[i] == '>' && s[i] == '>')
		return (1);
	return (0);
}

int		is_heredoc(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (s[i] == '<' && s[i + 1] == '<')
		return (1);
	return (0);
}

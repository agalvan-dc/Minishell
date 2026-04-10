#include "../../minishell.h"

int		is_redirection(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (is_pipe(s, i) || is_output_chevron(s, i) || is_input_chevron(s, i) 
		|| is_append_chevron(s, i) || is_heredoc(s, i))
		return (1);
	return (0);
}

int		is_pipe(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (s[i] == '|' && s[i + 1] != '|')
		return (1);
	return (0);
}

int		is_file_redir(char *s, int i)
{
	if (is_output_chevron(s, i) || is_input_chevron(s, i) 
        || is_append_chevron(s, i))
		return (1);
	return (0);
}

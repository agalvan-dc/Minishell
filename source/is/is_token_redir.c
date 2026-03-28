#include "../minishell.h"

int		is_token_input_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == INPUT_CHEVRON)
		return (1);
	return (0);
}

int		is_token_append_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == OUTPUT_CHEVTON)
		return (1);
	return (0);
}

int		is_token_redir(t_token *token)
{
	if (!token)
		return (0);
	if (is_token_input_chevron(token) || is_token_output_chevron(token) 
		|| is_token_append_chevron(token)
		|| is_token_heredoc(token) || is_token_pipe(token) || token->id == TOKEN_REDIR)
		return (1);
	return (0);
}

int		is_token_pipe(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_PIPE)
		return (1);
	return(0);
}

int		is_token_heredoc(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_HEREDOC)
		return (1);
	return (0);
}

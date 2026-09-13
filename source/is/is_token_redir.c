/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_redir.c                                   :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		is_token_input_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_INPUT_CHEVRON)
		return (1);
	return (0);
}

int		is_token_append_chevron(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_APPEND_CHEVRON)
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

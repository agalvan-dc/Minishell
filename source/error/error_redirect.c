/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_redirect.c                                   :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		ft_check_error_token_basic_redir(t_token *token, t_redir *redir)
{
	if (!(is_token_file(token->next)) || !token->next)
	{
		ft_printf("Error : [next cmd after %s not found]\n]", redir->content);
		return (1);
	}
	return (0);
}

int		ft_check_error_token_heredoc(t_redir *redir)
{
	if (!redir->delimiter)
	{
		ft_printf("Error : [next file after %s not found]\n]", redir->content);
		return (1);
	}
	return (0);
}

int		ft_check_error_token_pipe(t_token *token, t_redir *redir)
{
	if (!(ft_get_next_cmd(token)))
	{
		ft_printf("Error : [next cmd after %s not found]\n]", redir->content);
		return (1);
	}
	else if (!(ft_get_prev_cmd(token)))
	{
		ft_printf("Error : [prev cmd before %s not found]\n]", redir->content);
		return (1);
	}
	return (0);
}

int		ft_check_error_token_redir(t_token *token)
{
	t_redir	*redir;
	int		res;

	res = 0;
	redir = ft_get_class(token);
	if (!redir)
		return (0);
	if (is_token_basic_redir(token))
		res = ft_check_error_token_basic_redir(token, redir);
	else if (is_token_heredoc(token))
		res = ft_check_error_token_heredoc(redir);
	else if (is_token_pipe(token))
		res = ft_check_error_token_pipe(token, redir);
	return (res);
}

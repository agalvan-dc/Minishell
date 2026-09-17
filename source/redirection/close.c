/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_close_fd_cmd(t_cmd *cmd)
{
	if (isnot_standard_fd(cmd->fd_in))
	{
		close(cmd->fd_in);
		cmd->fd_in = -1;
	}
	if (isnot_standard_fd(cmd->fd_out))
	{
		close(cmd->fd_out);
		cmd->fd_out = -1;
	}
}

void	ft_remove_tmp_file(t_token *token_heredoc)
{
	t_redir		*redir;
	t_file		*tmp_file;
	t_cmd		*prev_cmd;

	redir = ft_get_class(token_heredoc);
	if (!redir)
		return ;
	tmp_file = redir->tmp_file;
	if (!tmp_file)
		return ;
	prev_cmd = ft_get_prev_cmd(token_heredoc);
	if (prev_cmd && prev_cmd->fd_in == tmp_file->fd)
		prev_cmd->fd_in = -1;
	if (tmp_file->fd > 2)
		close(tmp_file->fd);
	tmp_file->fd = -1;
	if (tmp_file->name)
	{
		unlink(tmp_file->name);
		free(tmp_file->name);
	}
	free(tmp_file);
	redir->tmp_file = NULL;
}

void	ft_close_all_fd(t_env *env)
{
	t_token		*token;

	token = ft_get_first_token(env);
	if (!token)
		return ;
	while (token)
	{
		if (is_token_heredoc(token))
			ft_remove_tmp_file(token);
		token = token->next;
	}
	token = ft_get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
			ft_close_fd_cmd(ft_get_class(token));
		token = token->next;
	}
}

void	ft_close_other_fd(t_env *env, t_cmd *current)
{
	t_token		*token;
	t_cmd		*cmd;

	token = ft_get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token))
		{
			cmd = ft_get_class(token);
			if (cmd != current)
				ft_close_fd_cmd(cmd);
		}
		token = token->next;
	}
}

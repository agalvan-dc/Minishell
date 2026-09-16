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
		close(cmd->fd_in);
	if (isnot_standard_fd(cmd->fd_out))
		close(cmd->fd_out);
}

void	ft_remove_tmp_file(t_token *token_heredoc)
{
	t_redir		*redir;
	t_file		*tmp_file;

	redir = ft_get_class(token_heredoc);
	if (!redir)
		return ;
	tmp_file = redir->tmp_file;
	if (!tmp_file)
		return ;
	if (tmp_file->fd > 2)
		close(tmp_file->fd);
	if (tmp_file->name)
	{
		unlink(tmp_file->name);
		free(tmp_file->name);
	}
	free(tmp_file);
	redir->tmp_file = NULL;
}

void        ft_close_all_fd(t_env *env)
{
	t_token		*token;

	token = ft_get_first_token(env);
	if (!token)
		return ;
	while (token)
	{
		if (is_token_cmd(token))
			ft_close_fd_cmd(ft_get_class(token));
		else if (is_token_heredoc(token))
			ft_remove_tmp_file(token);
		token = token->next;
	}
}

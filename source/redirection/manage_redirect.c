/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirect.c                                  :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_open_next_file_with_flags(t_token *token, t_file *file)
{
	if (is_token_input_chevron(token))
		file->fd = open(file->name, O_RDONLY);
	else if (is_token_output_chevron(token))
		file->fd = open(file->name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (is_token_append_chevron(token))
		file->fd = open(file->name, O_WRONLY | O_APPEND | O_CREAT, 0644);
}

void	ft_manage_fd_heredoc(t_env *env, t_token *token)
{
	t_cmd	*prev_cmd;
	t_redir	*redir;
	char	*tmp_file_name;
	int		fd_tmp;

	redir = ft_get_class(token);
	prev_cmd = ft_get_prev_cmd(token);
	tmp_file_name = ft_heredoc_prompt(env, redir->delimiter, !redir->quoted);
	fd_tmp = open(tmp_file_name, O_RDONLY, 0777);
	redir->tmp_file = ft_init_file(ft_strdup(tmp_file_name), fd_tmp);
	if (prev_cmd)
		ft_change_fd_cmd(prev_cmd, fd_tmp, prev_cmd->fd_out);
}

void	ft_manage_fd_pipe(t_token *token)
{
	t_cmd	*prev_cmd;
	t_cmd	*next_cmd;
	int		fd[2];

	prev_cmd = ft_get_prev_cmd(token);
	next_cmd = ft_get_next_cmd(token);
	if (!next_cmd || !prev_cmd)
		return ;
	if (pipe(fd) == -1)
		return ;
	ft_change_fd_cmd(prev_cmd, prev_cmd->fd_in, fd[1]);
	ft_change_fd_cmd(next_cmd, fd[0], next_cmd->fd_out);
}

static void	ft_redir_open_error(t_env *env, char *name)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	env->error_processing += 1;
	ft_update_var_status_process(env, 1);
}

void	ft_manage_fd_basic_redir(t_env *env, t_token *token)
{
	t_cmd	*prev_cmd;
	t_file	*next_file;

	prev_cmd = ft_get_prev_cmd(token);
	next_file = ft_get_next_token_file(token);
	if (!prev_cmd || !next_file)
		return ;
	if (is_token_input_chevron(token))
	{
		ft_open_next_file_with_flags(token, next_file);
		if (next_file->fd == -1)
		{
			ft_redir_open_error(env, next_file->name);
			return ;
		}
		ft_change_fd_cmd(prev_cmd, next_file->fd, prev_cmd->fd_out);
	}
	else if (is_token_output_chevron(token)
		|| is_token_append_chevron(token))
	{
		ft_open_next_file_with_flags(token, next_file);
		if (next_file->fd == -1)
		{
			ft_redir_open_error(env, next_file->name);
			return ;
		}
		ft_change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
	}
}

void	ft_manage_fd_for_redir(t_env *env, t_token *token)
{
	if (is_token_basic_redir(token))
		ft_manage_fd_basic_redir(env, token);
	else if (is_token_pipe(token))
		ft_manage_fd_pipe(token);
	else if (is_token_heredoc(token))
		ft_manage_fd_heredoc(env, token);
}

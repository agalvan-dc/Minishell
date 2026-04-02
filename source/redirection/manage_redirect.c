#include "../minishell.h"

void	ft_open_next_file_with_flags(t_token *token, t_file *file)
{
	if (is_token_input_chevron(token))
	{
		close(file->fd);
		file->fd = open(file->name, O_RDONLY);
	}
	else if (is_token_output_chevron(token))
	{
		close(file->fd);
		file->fd = open(file->name, O_WRONLY | O_TRUNC);
	}
	else if (is_token_append_chevron(token))
	{
		close(file->fd);
		file->fd = open(file->name, O_WRONLY | O_APPEND);
	}
}

void	ft_manage_fd_heredoc(t_token *token)
{
	t_cmd	*prev_cmd;
	t_redir	*redir;
	char	*tmp_file_name;
	int		fd_tmp;

	redir = ft_get_class(token);
	prev_cmd = ft_get_prev_cmd(token);
	tmp_file_name = ft_heredoc_prompt(redir->limiter);
	fd_tmp = open(tmp_file_name, O_RDONLY, 0777);
	redir->tmp_file = ft_init_file(tmp_file_name, fd_tmp);
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
	pipe(fd);
	ft_change_fd_cmd(prev_cmd, prev_cmd->fd_in, fd[1]);
	ft_change_fd_cmd(next_cmd, fd[0], next_cmd->fd_out);
}

void	manage_fd_basic_redirection(t_token *token)
{
	t_cmd	*prev_cmd;
	t_file	*next_file;

	prev_cmd = ft_get_prev_cmd(token);
	next_file = ft_get_next_token_file(token);
	if (!prev_cmd)
		return ;
	if (is_token_input_chevron(token))
	{
		ft_open_next_file_with_flags(token, next_file);
		ft_change_fd_cmd(prev_cmd, next_file->fd, prev_cmd->fd_out);
	}
	else if (is_token_output_chevron(token))
	{
		ft_open_next_file_with_flags(token, next_file);
		ft_change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
	}
	else if (is_token_append_chevron(token))
	{
		ft_open_next_file_with_flags(token, next_file);
		ft_change_fd_cmd(prev_cmd, prev_cmd->fd_in, next_file->fd);
	}
}

void	ft_manage_fd_for_redir(t_token *token)
{
	if (is_token_basic_redir(token))
		ft_manage_fd_basic_redir(token);
	else if (is_token_pipe(token))
		ft_manage_fd_pipe(token);
	else if (is_token_heredoc(token))
		ft_manage_fd_heredoc(token);
}

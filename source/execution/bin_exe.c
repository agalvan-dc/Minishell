/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exe.c                                          :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int	ft_bin_execution(t_env *env, t_cmd *cmd, char **var)
{
	int			pid;
	char		*path;
	int			status;
	struct stat	st;

	path = ft_get_cmd_path(cmd);
	if (path && stat(path, &st) == 0 && S_ISDIR(st.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": Is a directory", 2);
		cmd->pid = -1;
		return (126);
	}
	if (!path)
	{
		status = 127;
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->content, 2);
		if (ft_strchr(cmd->content, '/'))
		{
			if (access(cmd->content, F_OK) == -1)
				ft_putendl_fd(": No such file or directory", 2);
			else
			{
				ft_putendl_fd(": Permission denied", 2);
				status = 126;
			}
		}
		else
			ft_putendl_fd(": command not found", 2);
		cmd->pid = -1;
		return (status);
	}
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		if (!cmd_have_standard_fd(cmd))
		{
			ft_close_other_fd(env, cmd);
			ft_redirect_cmd(cmd);
		}
		execve(path, ft_get_cmd_args(cmd), var);
		perror("Command failure");
		free(path);
		exit(1);
	}
	else
		cmd->pid = pid;
	return (-1);
}

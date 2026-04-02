#include "../minishell.h"

void	ft_bin_execution(t_env *env, t_cmd *cmd, char **var)
{
	int		pid;
	char	*path;

	path = ft_get_cmd_path(cmd);
	if (!path)
		return ;
	pid = fork();
	if (pid == 0)
	{
		if (cmd_have_standard_fd(cmd))
		{
			execve(path, ft_get_cmd_args(cmd), var);
			perror("Command failure : ");
			exit(1);
		}
		else
		{
			ft_redirect_cmd(cmd);
			ft_close_all_fd(env);
			execve(path, ft_get_cmd_args(cmd), var);
			perror("Command failure : ");
			exit(1);
		}
	}
	else
		cmd->pid = pid;
}

#include "../../minishell.h"

void	ft_processing_redir(t_env *env)
{
	t_token	*token;

	if (have_token_redir(env))
	{
		token = ft_get_first_token_redirection(env);
		while (token)
		{
			ft_manage_fd_for_redir(token);
			token = ft_get_next_token_redirection(token);
		}
		if (env->verbose == 1)
		{
			printf("==== Processing Redirection ====\n");
			ft_print_all_redir_info(env);
			printf("-- Command Redirection --\n");
			ft_print_all_cmd_info(env);
			printf("======\n");
		}
	}
}

void	ft_change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out)
{
	cmd->fd_in = fd_in;
	cmd->fd_out = fd_out;
}

void	ft_redirect_cmd(t_cmd *cmd)
{
	int		fd_in;
	int		fd_out;

	fd_in = cmd->fd_in;
	fd_out = cmd->fd_out;
	if (isnot_standard_fd(fd_in))
	{
    	dup2(fd_in, STDIN_FILENO);
	    close(fd_in);
	}
	if (isnot_standard_fd(fd_out))
	{
    	dup2(fd_out, STDOUT_FILENO);
    	close(fd_out);
	}
}

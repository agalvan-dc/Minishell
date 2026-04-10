#include "../../minishell.h"

int		ft_execute_cmd(t_env *env, t_token *token)
{
	t_cmd	*cmd;
	char	**var;
	int		status_built;

	status_built = -1;
	cmd = ft_get_class(token);
	if (is_cmd_bin(cmd))
	{
		var = ft_get_env_var(env);
		ft_bin_execution(env, cmd, var);
		free_array(var);
	}
	else if (is_cmd_builtin(cmd))
		status_built = ft_builtin_execution(env, cmd);
	return (status_built);
}

void	ft_execution(t_env *env)
{
	t_token		*token;
	int			status;
	int			status_built;

	if (env->verbose == 1)
		printf("=== Execution ===\n");
	token = ft_get_first_token_cmd(env);
	while (token)
	{
		status_built = ft_execute_cmd(env, token);
		token = ft_get_next_token_cmd(token);
	}
	ft_close_all_fd(env);
	status = ft_wait_all_pid(env);
	status = ft_get_last_status(status, status_built);
	ft_update_var_status_process(env, status);
	if (env->verbose == 1)
		printf("======\n");
}

int		ft_wait_all_pid(t_env *env)
{
	t_token		*token;
	t_cmd		*cmd;
	int			status;

	token = ft_get_first_token_bin(env);
	if (!token)
		return (0);
	status = 0;
	while (token)
	{
		cmd = ft_get_class(token);
		waitpid(cmd->pid, &status, 0);
		status = ft_convert_status_process_value(status);
		token = ft_get_next_token_bin(token);
	}
	return (status);
}

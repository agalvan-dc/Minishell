#include "../minishell.h"

int		ft_built_in_execution(t_env *env, t_cmd *cmd)
{
	int		status;

	status = -1;
	if (is_echo(cmd))
		status = ft_echo(cmd);
	else if (is_cd(cmd))
		status = ft_cd(cmd);
	else if (is_env(cmd))
		status = ft_env_builtin(cmd, env);
	else if (is_export(cmd))
		status = ft_export_builtin(cmd, env);
	else if (is_pwd(cmd))
		status = ft_pwd(cmd);
	else if (is_unset(cmd))
		status = ft_unset(cmd);
	else if (is_exit(cmd))
	{
		status = 0;
		ft_exit_builtin(env, cmd);
	}
	return (status);
}

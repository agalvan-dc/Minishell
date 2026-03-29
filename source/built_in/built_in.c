#include "../minishell.h"

int     ft_echo(t_cmd *cmd)
{
    int     i;

    if (!cmd->arg && !cmd->args)
    {
        ft_putstr_fd("\n", cmd->fd_out);
        return (0);
    }
    i = 0;
    while (cmd->args[i])
    {
        ft_putstr_fd(cmd->args[i], cmd->fd_out);
        if (cmd->args[i + 1])
            ft_putstr_fd(" ", cmd->fd_out);
        i++;
    }
    if (!cmd->flags || !ft_is_flag_n(cmd->flags))
        ft_putstr_fd("\n", cmd->fd_out);
    return (0);
}

int		ft_cd(t_cmd *cmd, t_env *env)
{
	char	*path;
	char	*next_path;
	char	*prev_path;

	if (!cmd->arg)
		return (0);
	path = cmd->arg;	
	if (chdir(path) == -1)
	{
		ft_printf("%s : No such file or directory\n", path);
		return (1);
	}
	new_path = ft_get_current_path();
	last_path = ft_get_last_path(env);
	ft_change_env_var_value_with_name(env, "PWD", new_path);
	ft_change_env_var_value_with_name(env, "OLDPWD", last_path);
	return (0);
}

int		ft_pwd(t_cmd *cmd)
{
	char	*path;

	path = ft_get_current_path();
	ft_putstr_fd(path, cmd->out);
	ft_putstr_fd("\n", cmd->out);
	free(path);
	return (0);
}

int		ft_env_builtin(t_cmd *cmd, t_env *env)
{
	ft_print_all_env_var_fd(env, cmd->out);
	return (0);
}

int		ft_exit_builtin(t_cmd *cmd, t_env *env)
{
	int		signal;

	ft_putstr_fd("exit", 2);
	ft_putstr_fd("\n", 2);
	if (!cmd->arg)
		signal = 0;
	else
		signal = ft_atoi(cmd->arg);
	ft_remove_all(env);
	exit(signal);
}

#include "../../minishell.h"

int     ft_assign_env_var_id(char *value)
{
	if (!value)
		return (NON_VALUE);
	return (VALUE);
}

void	ft_change_or_create_var(t_env *env, char *name, char *value, int id)
{
	t_var	*var;

	if (is_variable_exist(env, name))
	{
		ft_change_env_var_value_with_name(env, name, value);
		free(name);
	}
	else
	{
		var = ft_init_env_var(name, value, id);
		ft_add_new_env_var(env, var);
	}
}

int		ft_export_builtin(t_cmd *cmd, t_env *env)
{
	char	*name;
	char	*value;
	int		id;

	if (!cmd->arg)
	{
		ft_print_all_env_export_var_fd(env, cmd->fd_out);
		return (0);	
	}
	name = ft_get_export_var_name(cmd->arg);
	if (!name)
	{	
		ft_putstr_fd("export : not a valid identifier\n", 1);
		return (1);
	}
	value = ft_get_env_var_value(cmd->arg);
	id = ft_assign_env_var_id(value);
	ft_change_or_create_var(env, name, value, id);
	return (0);
}

int		ft_unset(t_cmd *cmd, t_env *env)
{
	t_var	*var;
	char	*name;

	if (!cmd->arg)
		return (0);
	name = ft_get_var_name(cmd->arg);
	var = ft_get_env_var_with_name(env, name);
	if (var)
		ft_remove_and_disconnect_env_var(env, var);
	free(name);
	return (0);
}

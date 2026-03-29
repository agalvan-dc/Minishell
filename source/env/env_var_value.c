#include "../minishell.h"

void    ft_change_env_var_value(t_var *var, char *new_value)
{
	if (var->value)
		free(var->value);
	var->value = new_value;
	var->id = VALUE;
}

void	ft_change_env_var_value_with_name(t_env *env, char *name, char *value)
{
	t_var	*var;

	var = ft_get_env_var_value_with_name(env, name);
	if (!var)
		return ;
	ft_change_env_var_value(var, value);
}

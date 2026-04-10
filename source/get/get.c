#include "../../minishell.h"

t_var	*ft_get_first_env_var(t_env *env)
{
	if (env->first_var)
		return (env->first_var);
	return (NULL);
}

t_var	*ft_get_last_env_var(t_env *env)
{
	t_var	*var;

	var = ft_get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (!var->next)
			return (var);
		var = var->next;
	}
	return (NULL);
}

char	*ft_get_env_var_value_with_name(t_env *env, char *name)
{
	t_var	*var;

	var = ft_get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (is_same_name(var->name, name))
			return (var->value);
		var = var->next;
	}
	return (NULL);
}

t_var	*ft_get_env_var_with_name(t_env *env, char *name)
{
	t_var	*var;
	
	var = ft_get_first_env_var(env);
	if (!var)
		return (NULL);
	while (var)
	{
		if (is_same_name(var->name, name))
			return (var);
		var = var->next;
	}
	return (NULL);
}

int		ft_get_env_var_size(t_env *env)
{
	int		i;
	t_var	*var;

	i = 0;
	var = ft_get_first_env_var(env);
	if (!var)
		return (0);
	while (var)
	{
		i++;
		var = var->next;
	}
	return (i);
}

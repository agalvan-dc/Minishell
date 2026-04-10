#include "../../minishell.h"

void	ft_create_chained_var(t_env *env, char **env_variable)
{
	int		index;
	char	*name;
	char	*value;
	t_var	*var;

	index = 0;
	while (env_variable[index])
	{
		name = ft_get_var_name(env_variable[index]);
		value = ft_get_env_var_value(env_variable[index]);
		var = ft_init_env_var(name, value, VALUE);
		ft_add_var_list(env, var);
		index++;
	}
}

void	ft_add_new_env_var(t_env *env, t_var *new)
{
	t_var	*last_var;

	last_var = ft_get_last_env_var(env);
	if (!last_var)
		return ;
	ft_connect_new_var(last_var, new, NULL);
	new->index = last_var->index + 1;
}

char	**ft_add_env_var(char **var, char *variable)
{
	int		last_index;
	char	**new_var;

	last_index = len_array(var);
	new_var = ft_arrayjoin_str(var, variable, last_index);
	return (new_var);
}

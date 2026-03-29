#include "../minishell.h"

char	**ft_get_env_var(t_env *env)
{
	if (env->env_vars)
		ft_remove_env_vars(env);
	env->vars = ft_var_list_to_array(env);
	return (env_vars);
}

char	**ft_get_env_bins(t_env *env)
{
	char	*path;
	char	**bins;

	path = ft_get_env_var_value_with_name(env, "PATH");
	if (!path)
		return (NULL);
	bins = ft_split(path, ':');
	return (bins);
}

t_line	*ft_get_first_line(t_env *env)
{
	if (env->first_line)
		return (env->first_line);
	return (NULL);
}

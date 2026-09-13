#include "../../minishell.h"

t_file	*ft_init_file(char *name, int fd)
{
	t_file	*file;

	file = (t_file *)ft_calloc(1, sizeof(t_file));
	if (!file)
		return (NULL);
	file->name = name;
	file->fd = fd;
	return (file);
}

t_env	*ft_init_env(char **env_var)
{
	t_env	*env;

	env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!env)
		return (NULL);
	ft_create_chained_var(env, env_var);
	ft_add_signal_env_var(env);
	free_array(env_var);
	g_env = env;
	return (env);
}

t_var	*ft_init_env_var(char *name, char *value, int id)
{
	t_var	*var;

	var = (t_var *)ft_calloc(1, sizeof(t_var));
	if (!var)
		return (NULL);
	var->name = name;
	var->index = -1;
	var->value = value;
	var->id = id;
	return (var);
}

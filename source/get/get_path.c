#include "../minishell.h"

char	*ft_get_home_path(t_env *env)
{
	char	*value;
	char	*path;

	value = ft_get_env_var_value_with_name(env, "HOME");
	path = ft_substr(value);
	return (path);
}

char	*ft_get_current_path(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		perror("getcwd() Error");
	return (path);
}

char	*ft_get_last_path(t_env *env)
{
	char	*path;
	char	*last_path;

	last_path = ft_get_env_var_value_with_name(env, "PWD");
	path = ft_substr(last_path);
	return (path);
}

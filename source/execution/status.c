#include "../minishell.h"

int		ft_get_last_status(int bin_status, int ret_builtin)
{
	if (ret_builtin == -1)
		return (bin_status);
	else if (bin_status == -1)
		return (ret_builtin);
	return (0);
}

int	ft_convert_status_process_value(int status)
{
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (status);
}

void	ft_update_var_status_process(t_env *env, int status)
{
	t_var	*var;
	char	*value;

	value = ft_itoa(status);
	if (!value)
		return ;
	var = ft_get_env_var_with_name(env, "?");
	if (!var)
	{
		free(value);
		return ;
	}
	ft_change_env_var_value(var, value);
}

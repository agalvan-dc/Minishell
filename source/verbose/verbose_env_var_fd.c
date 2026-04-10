#include "../../minishell.h"

void	ft_print_env_var_fd(t_var *var, int fd)
{
	(void)fd;
	if (!var || !var->name)
		return ;
	if (!var->value)
		ft_printf_fd(fd, "%s\n", var->name);
	else
		ft_printf_fd(fd, "%s=%s\n", var->name, var->value);
}

void	ft_print_all_env_var_fd(t_env *env, int fd)
{
	t_var	*var;

	(void)fd;
	var = ft_get_first_env_var(env);
	if (!var)
		return ;
	while (var)
	{
		if (var->id == VALUE)
			ft_print_env_var_fd(var, fd);
		var = var->next;
	}
}

void	ft_print_all_env_export_var_fd(t_env *env, int fd)
{
	    t_var   *var;

    (void)fd;
    var = ft_get_first_env_var(env);
    if (!var)
        return ;
    while (var)
    {
        ft_print_env_var_fd(var, fd);
        var = var->next;
    }
}

#include "../minishell.h"

void	ft_print_env_var(t_var *var)
{
	if (!var || !var->name)
		return ;
	if (!var->value)
		ft_printf("%s\n", var->name);
	else
		ft_printf("%s=%s\n", var->name, var->value);
}

void	ft_print_all_env_var(t_env *env)
{
	t_var	*var;

	var = ft_get_first_env_var(env);
	if (!var)
		return ;
	while (var)
	{
		if (var->id == VALUE)
			ft_print_env_var(var);
		var = var->next;
	}
}

void	ft_print_all_env_export_var(t_env *env)
{
	t_var	*var;

	 var = ft_get_first_env_var(env);
    if (!var)
        return ;
    while (var)
    {
        ft_print_env_var(var);
        var = var->next;
    }
}

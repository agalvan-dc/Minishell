#include "../../minishell.h"

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

	var = ft_get_env_var_with_name(env, name);
	if (!var)
		return ;
	ft_change_env_var_value(var, value);
}

void ft_sigint_handler(int sig)
{
    (void)sig;
    write(1, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
    if (g_env)
	ft_update_var_status_process(g_env, 130);
}

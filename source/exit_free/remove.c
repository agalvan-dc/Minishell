#include "../minishell.h"

void	ft_remove_line(t_line *line)
{
	if (line->content)
		free(line->content);
	free(line);
}

void	ft_remove_all_line(t_env *env)
{
	t_line	*line;
	t_line	*iter;

	line = ft_get_first_line(env);
	if (!line)
		return ;
	iter = line;
	while (iter)
	{
		iter = iter->next;
		ft_disconnect_line(line);
		ft_remove_line(line);
		line = iter;
	}
	env->first_line = NULL;
}

void	ft_remove_env_var(t_var *var)
{
	if (var->name)
		free(var->name);
	var->name = NULL;
	if (var->value)
		free(var->value);
	var->value = NULL;
	if (var)
		free(var);
	var = NULL;
}

void	ft_remove_var_list(t_env *env)
{
	t_var	*var;
	t_var	*iter;

	var = ft_get_first_env_var(env);
	if (!var)
		return ;
	var = iter;
	while (iter)
	{
		iter = iter->next;
		ft_disconnect_env_var(env, var);
		ft_remove_env_var(var);
		var = iter;
	}
	env->first->var = NULL;
}

void	ft_remove_all(t_env *env)
{
	ft_remove_all_token(env);
	ft_remove_var_list(env);
	ft_remove_all_line(env);
	ft_remove_env_var(env);
	free(env);
}

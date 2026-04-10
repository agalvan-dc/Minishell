#include "../../minishell.h"

void	ft_remove_arg(t_arg *arg)
{
	ft_disconnect_args(arg);
	if (arg->content)
	{
		free(arg->content);
		arg->content = NULL;
	}
	if (arg)
	{
		free(arg);
		arg = NULL;
	}
}

void	ft_remove_all_arg(t_cmd *cmd)
{
	t_arg	*arg;
	t_arg	*iter;

	if (!(cmd->first_arg))
		return ;
	arg = cmd->first_arg;
	while (arg)
	{
		iter = arg->next;
		ft_remove_arg(arg);
		arg = iter;
	}
	cmd->first_arg = NULL;
}

void    ft_remove_arg_index(t_cmd *cmd, t_arg *arg)
{
    t_arg   *iter;
    int     i;

    i = 1;
    iter = cmd->first_arg;
    while (iter && i < arg->index)
    {
        iter = iter->next;
        i++;
    }
    if (!iter)
        return ;
    if (iter->prev)
        iter->prev->next = iter->next;
    else
        cmd->first_arg = iter->next;
    if (iter->next)
        iter->next->prev = iter->prev;
	ft_remove_arg(iter);
}

void	ft_remove_env_vars(t_env *env)
{
	if	(env->env_vars)
		free_array(env->env_vars);
	env->env_vars = NULL;
}

void	ft_remove_arg_in_cmd(t_cmd *cmd, t_arg *arg)
{
	if (arg->index == 1 && !arg->next)
		cmd->first_arg = NULL;
	else if (arg->next)
		cmd->first_arg = arg->next;
	ft_remove_arg(arg);
}

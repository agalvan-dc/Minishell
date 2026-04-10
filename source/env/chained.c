#include "../../minishell.h"

void	ft_add_var_list(t_env *env, t_var *var)
{
	int		i;
	t_var	*iter;

	i = 0;
	if (!(env->first_var))
	{
		env->first_var = var;
		var->index = i;
	}
	else
	{
		iter = env->first_var;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		var->index = i;
		ft_connect_var(iter, var);
	}
}

void	ft_add_token_list(t_env *env, t_token *token)
{
	t_token 	*iter;
	int			i;

	i = 0;
	if (!(env->first_token))
	{
		env->first_token = token;
		token->index = i;
	}
	else
	{
		iter = env->first_token;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		token->index = i;
		ft_connect_token(iter, token);
	}
}

void	ft_add_arg_list(t_cmd *cmd, t_arg *arg)
{
	t_arg	*iter;
	int		i;

	i = 0;
	if (!(cmd->first_arg))
	{
		cmd->first_arg = arg;
		arg->index = i;
	}
	else
	{
		iter = cmd->first_arg;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		arg->index = i;
		ft_connect_arg(iter, arg);
	}
}

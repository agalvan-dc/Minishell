#include "../../minishell.h"

void    ft_remove_blank_arg(t_cmd *cmd)
{
	t_arg	*arg;
	t_arg	*iter;

	iter = ft_get_first_arg(cmd);
	arg = iter;
	while (iter)
	{
		iter = arg->next;
		if (is_arg_blank(arg))
		{
			if (arg->index == 1)
				cmd->first_arg = arg->next;
			ft_remove_arg(arg);
		}
		arg = iter;
	}
}

void	ft_concatenate_cmd_args(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;

	token = env->first_token;
	while (token)
	{
		if (is_token_cmd(token))
		{
			cmd = ft_get_class(token);
			if (cmd_have_args(cmd))
			{
				ft_remove_blank_arg(cmd);
				cmd->args = ft_cmd_list_to_array(cmd);
				if (is_cmd_builtin(cmd) && cmd->args)
					cmd->arg = cmd->args[0];
			}
		}
		token = token->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_remove_blank_arg(t_cmd *cmd)
{
	t_arg	*arg;
	t_arg	*iter;

	arg = ft_get_first_arg(cmd);
	while (arg)
	{
		iter = arg->next;
		if (is_arg_blank(arg))
			ft_remove_arg_in_cmd(cmd, arg);
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
					cmd->arg = malloc_strcpy(cmd->args[0]);
			}
		}
		token = token->next;
	}
}

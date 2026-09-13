/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_cmd.c                                         :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		cmd_have_args(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->first_arg)
		return (1);
	return (0);
}

int		cmd_have_argument(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_env(cmd) || is_pwd(cmd) || is_cd(cmd) || is_export(cmd) 
		|| is_exit(cmd) || is_echo(cmd) || cmd->args || cmd->arg)
		return (1);
	return (0);
}

int		cmd_have_arg_flags(t_cmd *cmd)
{
	t_arg	*arg;

	if (!(cmd_have_args(cmd)))
		return (0);
	arg = ft_get_first_arg(cmd);
	while (arg)
	{
		if (is_arg_flags(arg))
			return (1);
		arg = arg->next;
	}
	return (0);
}

int		cmd_have_flags(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->flags)
		return (1);
	return (0);
}

int		cmd_have_args_array(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->args)
		return (1);
	return (0);
}

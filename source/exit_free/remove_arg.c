/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_arg.c                                       :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_remove_arg(t_arg *arg)
{
	if (arg->content)
		free(arg->content);
	arg->content = NULL;
	free(arg);
}

void	ft_remove_arg_in_cmd(t_cmd *cmd, t_arg *arg)
{
	if (!arg)
		return ;
	if (cmd->first_arg == arg)
		cmd->first_arg = arg->next;
	ft_disconnect_args(arg);
	ft_remove_arg(arg);
}

void	ft_remove_arg_index(t_cmd *cmd, t_arg *arg)
{
	ft_remove_arg_in_cmd(cmd, arg);
}

void	ft_remove_all_arg(t_cmd *cmd)
{
	t_arg	*iter;
	t_arg	*next;

	if (!cmd)
		return ;
	iter = cmd->first_arg;
	while (iter)
	{
		next = iter->next;
		ft_remove_arg(iter);
		iter = next;
	}
	cmd->first_arg = NULL;
	if (cmd->args)
		free_array(cmd->args);
	cmd->args = NULL;
}

void	ft_remove_env_vars(t_env *env)
{
	if (env->env_vars)
		free_array(env->env_vars);
	env->env_vars = NULL;
}
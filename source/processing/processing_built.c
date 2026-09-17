/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing_built.c                                 :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void    ft_processing_exit(t_env *env, t_cmd *cmd)
{
	int		nb;
	long	signal;
	t_arg	*arg;
	char	*status;

	nb = ft_get_number_args(cmd);
	ft_putstr_fd("exit\n", 2);
	if (nb > 1)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		env->error_processing += 1;
		ft_update_var_status_process(env, 1);
		return ;
	}
	if (nb == 1)
	{
		arg = ft_get_first_arg(cmd);
		if (!is_numeric(arg->content))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(arg->content, 2);
			ft_putendl_fd(": numeric argument required", 2);
			ft_remove_all(env);
			exit(2);
		}
		signal = ft_atoi(arg->content);
	}
	else
	{
		status = ft_get_env_var_value_with_name(env, "?");
		signal = status ? ft_atoi(status) : 0;
	}
	ft_remove_all(env);
	exit((unsigned char)signal);
}

void    ft_processing_echo(t_cmd *cmd)
{
	t_arg	*arg;

	if (cmd_have_arg_flags(cmd))
	{
		arg = ft_get_cmd_flags(cmd);
		cmd->flags = malloc_strcpy(arg->content);
		if (is_arg_blank(arg->next))
			ft_remove_arg_in_cmd(cmd, arg->next);
		ft_remove_arg_in_cmd(cmd, arg);
	}
}

void    ft_processing_cd(t_env *env, t_cmd *cmd)
{
	if (!(cmd_have_args(cmd)))
		cmd->arg = ft_get_home_path(env);
}

void    ft_choose_processing_builtin(t_env *env, t_cmd *cmd)
{
	if (is_cd(cmd))
		ft_processing_cd(env, cmd);
	else if (is_echo(cmd))
		ft_processing_echo(cmd);
	else if (is_exit(cmd))
		ft_processing_exit(env, cmd);
}

void	ft_processing_builtin(t_env *env)
{
	t_token	*token;
	t_cmd	*cmd;

	token = ft_get_first_token_builtin(env);
	while (token)
	{
		cmd = ft_get_class(token);
		ft_choose_processing_builtin(env, cmd);
		token = ft_get_next_token_builtin(token);
	}
}

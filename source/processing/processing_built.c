#include "../minishell.h"

void    ft_processing_exit(t_cmd *cmd)
{
	int		nb;

	nb = ft_get_number_args(cmd);
	if (nb > 2)
	{
		ft_putstr_fd("Too many argument\n", 1);
		ft_remove_all_arg(cmd);
	}
}

void    ft_processing_echo(t_cmd *cmd)
{
	t_arg	*arg;

	if (cmd_have_arg_flags(cmd))
	{
		arg = ft_get_cmd_flags(cmd);
		cmd->flags = ft_substr(arg->content);
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
		ft_processing_exit(cmd);
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

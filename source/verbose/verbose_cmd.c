#include "../minishell.h"

void	ft_print_cmd_info(t_cmd *cmd)
{
	ft_printf(" ---[%s]---\n", cmd->content);
	ft_printf("");
	if (is_cmd_bin(cmd))
	{
		ft_printf(" | path : [%s]\n", cmd->bin);
		ft_printf(" | args : [");
		ft_print_array(cmd->args);
		ft_printf("]\n");
	}
	else if (is_cmd_builtin(cmd))
	{
		ft_printf(" | arg : [%s]\n", cmd->arg);
		ft_printf(" | flags : [%s]\n", cmd->flags);
	}
	ft_printf(" | fd_in : [%d]\n", cmd->fd_in);
	ft_printf(" | fd_out : [%d]\n", cmd->fd_out);
	if (cmd_have_args(cmd))
		ft_print_args(cmd);
	ft_printf(" ----------\n");
}

void	ft_print_all_cmd_info(t_env *env)
{
	t_token		*token;
	t_cmd		*cmd;

	token = ft_get_first_token_cmd(env);
	while (token)
	{
		if (is_token_cmd(token))
		{
			cmd = ft_get_class(token);
			ft_print_cmd_info(cmd);
		}
		token = ft_get_next_token_cmd(token);
	}
}

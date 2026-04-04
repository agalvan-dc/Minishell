#include "../minishell.h"

void    ft_print_args_array(char **args)
{
	int		i;

	i = 0;
	if (!args)
		return ;
	ft_printf("	[ARGS] : [");
	while (args[i])
	{
		ft_printf("%s", args[i]);
		i++;
	}
	ft_printf("]\n");
}

void    ft_print_args(t_cmd *cmd)
{
	t_arg	*iter;
	int		i;

	i = 1;
	iter = cmd->first-arg;
	if (!iter)
		return ;
	while (iter)
	{
		ft_printf("	[%d][%d : [%s]\n]", i, iter->id, iter->contenr);
		i++;
		iter = iter->next;
	}
	ft_printf("\n");
}


void	ft_print_cmd(t_cmd *cmd, int index)
{
	ft_printf("[%d][%d] : [%s]\n", index, cmd->id, cmd->content);
	if (cmd_have_args(cmd))
		ft_print_args(cmd);
	else if (cmd_have_args_array(cmd))
		ft_print_args_array(cmd->args);
}

void	ft_print_redir(t_token *token, t_redir *redir)
{
	ft_printf("[%d][%d] : [%s]\n", token->index, redir->type, redir->content);
	if (redir->type == TOKEN_HEREDOC)
		 ft_printf("	[%s][%s]\n", "TOKEN_LIMITER", redir->limiter);
	else
	{
		 ft_printf("	[FD_IN : %d]\n", redir->fd_in);
		 ft_printf("	[FD_OUT : %d]\n", redir->fd_out);
	}
	 ft_printf("\n");
}

#include "../minishell.h"

int		check_error_token_cmd(t_token *token)
{
	int		res;
	t_cmd	*cmd;
	t_cmd	*next_cmd;
	t_cmd	*prev_cmd;

	res = 0;
	cmd = ft_get_class(token);
	if (!cmd)
		return (res);
	if (is_token_cmd(token->next))
	{
		next_cmd = ft_get_class(token->next);
		ft_printf("Error : [ Two following cmd %s && %s\n]", cmd->content, next_cmd->content);
		res += 1;
	}
	else if (is_token_cmd(token->prev))
	{
		prev_cmd = ft_get_class(token->prev);
        ft_printf("Error : [ Two following cmd %s && %s\n]", cmd->content, prev_cmd->content);
		res += 1;
	}
	if (is_cmd_builtin(cmd))
		res += ft_check_error_builtin(cmd);
	return (res);
}

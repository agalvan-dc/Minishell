#include "../minishell.h"

int		is_token_cmd(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_CMD || is_token_bin(token) || is_token_builtin(token))
		return (1);
	return (0);
}

int		is_token_bin(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_BIN)
		return (1);
	return (0);
}

int		is_token_builtin(t_token *token)
{
	if (!token)
		return (0);
	if (token->id == TOKEN_BUILTIN)
		return (1);
	return (0);
}

int		is_cmd_bin(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->id == TOKEN_BIN || cmd->id == TOKEN_CMD)
		return (1);
	return (0);
}

int		is_cmd_builtin(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (cmd->id == TOKEN_CMD || cmd->id == TOKEN_BUILTIN)
}

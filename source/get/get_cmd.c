#include "../minishell.h"

t_token		*ft_get_first_token_cmd(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token		*ft_get_first_token_builtin(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_builtin(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token		*ft_get_first_token_bin(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_bin(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_cmd		*ft_get_prev_cmd(t_token *token)
{
	while (token)
	{
		if (is_token_cmd(token))
			return (get_class(token))
		token = token->prev;
	}
	return (NULL);
}

char		*ft_get_cmd_path(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (cmd->bin)
		return (cmd->bin);
	return (NULL);
}

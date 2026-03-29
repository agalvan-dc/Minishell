#include "../minishell.h"

t_token	*ft_get_next_token_cmd(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*ft_get_next_token_builtin(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_builtin(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*ft_get_next_token_bin(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_bin(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*ft_get_next_token_file(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_file(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token	*ft_get_next_cmd(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_cmd(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

#include "../minishell.h"

t_token		*ft_get_first_token_redirection(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_redir(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_token		*ft_get_next_token_redirection(t_token *token)
{
	token = token->next;
	while (token)
	{
		if (is_token_redir(token))
			return (token);
		token = token->next;
	}
	return (NULL);
}

t_redir	*ft_get_first_redirection(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_redir(token))
			return (ft_get_class(token));
		token = token->next;
	}
	return (NULL);
}

int			ft_get_nbr_pipes(t_env *env)
{
	t_token	*token;
	int		cont;

	cont = 0;
	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_pipe(token))
			cont += 1;
		token = token->next;
	}
	return (cont);
}

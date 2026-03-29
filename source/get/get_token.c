#include "../minishell.h"

t_token	*ft_get_first_token(t_env *env)
{
	if (env->first_token)
		return(env->first_token);
	return (NULL);
}

t_cmd	*ft_get_first_cmd(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return (NULL);
	while (token)
	{
		if (is_token_cmd(token))
			return (ft_get_class(token));
		token = token->next;
	}
	return (NULL);
}

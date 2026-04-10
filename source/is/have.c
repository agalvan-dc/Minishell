#include "../../minishell.h"

int		have_token(t_env *env)
{
	if (env->first_token)
		return (1);
	return (0);
}

int		token_have_args(t_token *token)
{
	if (((t_cmd *)token->class)->first_arg)
		return (1);
	return (0);
}

int		have_token_redir(t_env *env)
{
	t_token		*token;

	if (!(have_token(env)))
		return (0);
	token = ft_get_first_token(env);
	while (token)
	{
		if (is_token_redir(token))
			return (1);
		token = token->next;
	}
	return (0);
}

#include "../minishell.h"

void	ft_remove_token(t_token *token)
{
	if (is_token_cmd(token))
		ft_remove_token_cmd(ft_get_class(token));
	else if (is_token_redir(token))
		ft_remove_token_redir(ft_get_class(token));
	else if (is_token_file(token))
		ft_remove_token_file(ft_get_class(token));
	else if (is_token_word(token))
		ft_remove_token_word(ft_get_class(token));
	free(token);
}

void	ft_remove_all_token(t_env *env)
{
	t_token	*token;
	t_token	*iter;

	if (!(env->first_token))
		return ;
	token = ft_get_first_token(env);
	if (!token)
		return ;
	while (token)
	{
		iter = token->next;
		ft_disconnect_token(token);
		ft_remove_token(token);
		token = iter;
	}
	env->first_token = NULL;
}

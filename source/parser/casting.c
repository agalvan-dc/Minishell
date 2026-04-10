#include "../../minishell.h"

void	*ft_get_class(t_token *token)
{
	if (is_token_cmd(token))
		return ((t_cmd *)token->class);
	else if (is_token_redir(token))
		return ((t_redir *)token->class);
	else if (is_token_file(token))
		return ((t_file *)token->class);
	else if (is_token_word(token))
		return ((t_word *)token->class);
	return (NULL);
}

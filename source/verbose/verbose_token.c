#include "../../minishell.h"

void	ft_print_token(t_token *token)
{
	if (is_token_redir(token))
		ft_print_redir(token, ft_get_class(token));
	else if (is_token_cmd(token))
		ft_print_cmd(ft_get_class(token), token->index);
	else if (is_token_file(token))
	{
		ft_printf("[%d][%d] : [%s]\n", token->index,token->id,
		 ((t_file *)token->class)->name);
		ft_printf("   [FD : %d]\n\n", ((t_file *)token->class)->fd);
	}
	else
		ft_printf("[%d][%d] : [%s]\n\n", token->index,
			token->id, ((t_word *)token->class)->content);
}

void	ft_print_chained_list(t_env *env)
{
	t_token	*iter;

	iter = env->first_token;
	ft_printf("==== Parsing ====\n");
	while (iter)
	{
		ft_print_token(iter);
		iter = iter->next;
	}
	ft_printf("=========\n");
}

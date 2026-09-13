/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_check_error_parsing(t_env *env)
{
	t_token	*token;

	token = ft_get_first_token(env);
	if (!token)
		return ;
	while (token)
	{
		if (is_token_cmd(token))
			env->error_parsing += ft_check_error_token_cmd(token);
		if (is_token_redir(token))
			env->error_parsing += ft_check_error_token_redir(token);
		if (is_token_word(token))
			env->error_parsing += ft_check_error_token_word(env, token);
		token = token->next;
	}
	return ;
}

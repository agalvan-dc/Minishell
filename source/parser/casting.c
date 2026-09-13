/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
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

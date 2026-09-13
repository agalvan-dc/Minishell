/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_quote.c                                         :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		is_double_quote(char c)
{
	if (c == '\"')
		return (1);
	return (0);
}

int		is_single_quote(char c)
{
	if (c == '\'')
		return (1);
	return (0);
}

int		is_quote(char c)
{
	if (is_double_quote(c) || is_single_quote(c))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arg.c                                           :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		is_arg_var(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_VARIABLE)
		return (1);
	return (0);
}

int		is_arg_flags(t_arg *arg)
{
	if(!arg)
		return (0);
	if (arg->id == TOKEN_FLAGS)
		return (1);
	return (0);
}

int		is_arg_blank(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_BLANK)
		return (1);
	return (0);
}

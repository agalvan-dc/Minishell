/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_arg.c                                       :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		is_arg(char *s, int i)
{
	if (!(is_separator(s, i)) && !(is_blank(s[i])))
		return (1);
	return (0);
}

int		is_flags(char *s, int i)
{
	if (index_is_overflow(s, i))
		return (0);
	if (s[i] == '-' && s[i + 1] == 'n')
		return (1);
	return (0);
}

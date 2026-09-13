/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		is_file (char *s, int i)
{
	if (!(is_quote(s[i])) && !(is_blank(s[i])) 
	&& !(is_separator(s, i)) && is_after_redirect(s, i))
		return (1);
	return (0);
}

int		is_after_redirect(char *s, int i)
{
	i -= 1;
	while (i >= 0)
	{
		if (!(is_blank(s[i])))
		{
			if (is_file_redir(s, i))
				return (1);
			return (0);
		}
		i--;
	}
	return (0);
}

int		is_after_heredoc(char *s, int i)
{
	i -= 1;
	while (i >= 0)
	{
		if (!(is_blank(s[i])))
		{
			if (is_heredoc(s, i))
				return (1);
			return (0);
		}
		i--;
	}
	return (0);
}

int		is_limiter(char *s, int i)
{
	if (is_after_heredoc(s, i) && !(is_file(s, i)))
		return (1);
	return (0);
}

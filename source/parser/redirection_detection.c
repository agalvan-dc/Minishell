/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_detection.c                            :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		ft_redirection_detection(char *line, int index)
{
	if (is_heredoc(line, index) || is_append_chevron(line, index))
		return (index + 1);
	return (index);
}

int		ft_limiter_detection(char *line, int index)
{
	while (line[index])
	{
		if (is_blank(line[index]) || is_separator(line, index))
			return (index - 1);
		else if (is_double_quote(line[index]))
			index = ft_double_quote_detection(line, index);
		else if (is_single_quote(line[index]))
			index = ft_single_quote_detection(line, index);
		index++;
	}
	return (index - 1);
}



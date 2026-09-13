/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_extraction.c                              :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		ft_arg_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_index;

	new_index = index;
	if (is_flags(line, index))
	{
		new_index = ft_flags_tokenizer(env, cmd, line, index);
		index = new_index;
	}
	while (!(line_is_finish(line, index)) && !(is_separator(line, index)))
	{
		index = ft_blank_detection(line, index);
		if (line_is_finish(line, index) || is_separator(line, index))
		{
			new_index = index;
			break ;
		}
		new_index = ft_arg_classification(env, cmd, line, index);
		index = new_index;
		index++;
	}
	return (new_index);
}

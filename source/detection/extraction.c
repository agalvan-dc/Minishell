/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extraction.c                                       :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		ft_arg_redirect_extraction(t_token *token, t_env *env, char *line, int i)
{
	if (is_token_heredoc(token))
		i = ft_limiter_extraction(ft_get_class(token), line, i + 1);
	else if (is_token_basic_redir(token))
		i = ft_next_file_tokenizer(env, line, i + 1);
	return (i);
}

int     ft_word_arg_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
    char    *content;
    int     start;

    start = index;
    while (line[index] && !(is_word_arg_sep(env, line, index)))
        index++;
    content = malloc_substrcpy(line, start, index - 1);
    ft_word_arg_tokenizer(env, cmd, content);
    free(content);
    return (index - 1);
}

int     ft_string_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
    t_arg   *arg;
    int     start;

    start = index;
    while (line[index] && !is_double_quote(line[index])
        && !is_variable(env, line, index))
        index++;
    arg = ft_arg_tokenizer(line, start, index - 1, TOKEN_STRING);
    ft_add_arg_list(cmd, arg);
    return (index - 1);
}

static void	ft_strip_delimiter_quotes(t_redir *redir)
{
	int		len;
	char	quote;
	char	*stripped;

	len = ft_strlen(redir->delimiter);
	if (len < 2)
		return ;
	quote = redir->delimiter[0];
	if (quote != '\'' && quote != '"')
		return ;
	if (redir->delimiter[len - 1] != quote)
		return ;
	stripped = ft_substr(redir->delimiter, 1, len - 2);
	free(redir->delimiter);
	redir->delimiter = stripped;
	redir->quoted = 1;
}

int		ft_limiter_extraction(t_redir *redir, char *line, int i)
{
	int		new_i;

	if (is_finish(line[i]))
		return (i);
	while (line[i])
	{
		if (!(is_blank(line[i])))
		{
			new_i = ft_limiter_detection(line, i);
			redir->delimiter = ft_substr(line, i, new_i - i + 1);
			if (redir->delimiter)
				ft_strip_delimiter_quotes(redir);
			return (new_i);
		}
		i++;
	}
	return (i);
}

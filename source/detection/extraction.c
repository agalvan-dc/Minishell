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
    return (index);
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

int		ft_limiter_extraction(t_redir *redir, char *line, int i)
{
	int		new_i;
	int		start;

	start = i;
	if (is_finish(line[i]))
		return (start);
	while (line[i])
	{
		if (!(is_blank(line[i])))
		{
			new_i = ft_limiter_detection(line, i);
			redir->delimiter = ft_substr(line, i, new_i);
		}
		i++;
	}
	return (start);
}

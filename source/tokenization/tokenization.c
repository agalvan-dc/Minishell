#include "../minishell.h"

void	ft_tokenization(t_env *env, char *line)
{
	int		index;

	index = 0;
	while (!(line_is_finish(line, index)))
	{
		if (is_word(env, line, index))
			index = ft_word_classification(env, line, index);
		if (is_redirection(line, index))
			index = ft_redir_classification(env, line, index);
		index++;
	}
}

int		ft_single_tokenization(t_cmd *cmd, char *line, int start, int index)
{
	t_arg	*arg;
	char	*content;

	if (is_finish(line[index]))
		content = ft_get_rest_single_token(line, start, index, "\'");
	else
	{
		content = ft_substr(line, start, index);
		index++;
	}
	arg = ft_create_arg(content, TOKEN_SINGLE_QUOTE);
	ft_add_arg_list(cmd, arg);
	return (index);
}

t_token	*ft_cmd_tokenization(char *word, int fd)
{
	t_token	*token;

	token = ft_create_token_command(id, word);
	return (token);
}

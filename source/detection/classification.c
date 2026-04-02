#include "../minishell.h"

int		ft_redir_classification(t_env *env, char *line, int i)
{
	t_token	*token;
	int		new_i;

	new_i = ft_redirection_detection(line, i);
	token = ft_create_token_redir(line, i, new_i);
	ft_add_token_list(env, token);
	i = ft_arg_redirect_extraction(env, token, line, new_i);
	return (i);
}

int		ft_word_classification(t_env *env, char *line, int i)
{
	char	*content;
	int		new_i;
	t_token	*token;

	new_i = ft_word_detection(env, line, i);
	content = ft_substr(line, i, new_i);
	if (is_cmd(env, content))
		new_index = ft_cmd_tokenizer(env, line, content, new_i + 1);
	else
	{
		token = ft_word_tokenizer(content, TOKEN_WORD);
		ft_add_token_list(env, token);
	}
	return (new_i);
}

t_token	*ft_cmd_classification(t_env *env, char *content)
{
	t_token	*token;

	token = NULL;
	if (is_builtin(content))
		token = ft_cmd_tokenization(content, TOKEN_BUILTIN);
	else if (is_bin(env, content))
		token = ft_cmd_tokenization(content, TOKEN_BIN);
	return (token);
}

int		ft_arg_classification(t_env *env, t_cmd *cmd, char *line, int i)
{
	int		new_i;

	new_i = i;
	if (is_blank_arg(env, line, i))
		new_i = ft_blank_arg_tokenizer(env, cmd, line, i);
	else if (is_single_quote(line[i]))
		new_i = ft_single_tokenizer(cmd, line, i);
	else if (is_double_quote(line[i]))
		new_i = ft_double_tokenizer(env, cmd, line, i);
	else if (is_variable_word(line, i))
		new_i = ft_variable_tokenizer(env, cmd, line, i);
	else if (is_word(env, line, i))
		new_i = ft_word_arg_extraction(env, cmd, line, i);
	return (new_i);
}

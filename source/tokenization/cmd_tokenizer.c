#include "../minishell.h"

int		ft_cmd_tokenizer(t_env *env, char *line, char *content, int index)
{
	t_token	*token;

	token = ft_cmd_classification(env, content);
	if (!(index_is_overflow(line, index)) && !(is_separator(line, index)))
	{
		index = ft_blank_detection(line, index);
		index = ft_arg_extraction(env, ft_get_class(token), line, index);
	}
	ft_add_token_list(env, token);
	return (index);
}

t_arg	*ft_arg_tokenizer(char *line, int start, int end, int fd)
{
	t_arg	*arg;
	char	*content;

	if (!line)
		content = NULL;
	else
		content = ft_substr(line, start, end);
	arg = ft_create_arg(content, id);
	return (arg);
}

int     ft_flags_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
    t_arg   *arg;
    int     start;

    start = index;
    while (line[index] && !is_delimiter(env, line, index))
        index++;
    arg = ft_arg_tokenizer(line, start, index - 1, TOKEN_FLAGS);
    ft_add_arg_list(cmd, arg);
    return (index);
}

int		ft_var_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_i;

	if (is_variable(env, line, index))
		new_i = ft_vars_tokenization(env, cmd, line, index);
	else
		new_i = ft_word_arg_detection(env, line, index);
	return (new_i);
}

int		ft_vars_tokenization(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_i;
	char	*name;
	t_arg	*arg;

	new_i = ft_variable_detection(line, index + 1);
	name = ft_substr(line, index, new_i);
	if (is_variable_exist(env, name))
	{
		arg = ft_create_arg(name, TOKEN_VARIABLE);
		ft_add_arg_list(cmd, arg);
	}
	else
		free(name);
	return (new_i);
}

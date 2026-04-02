#include "../minishell.h"

int     ft_single_tokenizer(t_cmd *cmd, char *line, int index)
{
    int     start;

    index++;
    start = index;
    while (line[index] && !is_single_quote(line[index]))
    {
        if (is_backslash(line[index]))
            index++;
        index++;
    }
    return (ft_single_tokenization(cmd, line, start, index - 1));
}

void    ft_double_tokenization(t_env *env, t_cmd *cmd, char *content)
{
    int     index;
    int     new_i;

    new_i = 0;
    index = 0;
    while (content[index])
    {
        if (is_variable_word(content, index))
        {
            new_i = ft_vars_tokenization(env, cmd, content, i);
            i = new_i;
        }
        else
        {
            new_i = ft_string_extraction(env, cmd, content, i);
            i = new_i;
        }
        index++;
    }
}

int		ft_double_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		start;
	char	*content;

	index++;
	start = index;
	while (line[index] && !is_double_quote(line[index]))
	{
		if (is_backslash(line[index]))
			index++;
		index++;
	}
	content = ft_get_content_double(line, start, &index);
	ft_double_tokenization(env, cmd, content);
	return (free(content), index);
}

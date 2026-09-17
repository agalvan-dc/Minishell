/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_tokenizer.c                                  :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

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

static int	ft_is_escaped_double_quote_char(char c)
{
	if (c == '"' || c == '\\' || c == '$')
		return (1);
	return (0);
}

static char	*ft_unescape_double_substr(char *content, int start, int end)
{
	int		i;
	int		j;
	char	*res;

	i = start;
	j = 0;
	res = ft_calloc((end - start) + 2, sizeof(char));
	while (i <= end)
	{
		if (is_backslash(content[i]) && i + 1 <= end
			&& ft_is_escaped_double_quote_char(content[i + 1]))
			i++;
		res[j] = content[i];
		j++;
		i++;
	}
	return (res);
}

void    ft_double_tokenization(t_env *env, t_cmd *cmd, char *content)
{
    int     index;
    int     new_i;
    int     start;
    int     close_i;
    char    *result;
    char    *name;
    char    *value;
    char    *tmp;
    t_arg   *arg;

    index = 0;
    result = ft_strdup("");
    while (content[index])
    {
        if (content[index] == '$' && content[index + 1] == '{')
        {
            close_i = index + 2;
            while (content[close_i] && content[close_i] != '}')
                close_i++;
            if (close_i > index + 2)
                name = malloc_substrcpy(content, index + 2, close_i - 1);
            else
                name = ft_strdup("");
            value = ft_get_env_var_value_with_name(env, name);
            free(name);
            if (!value)
                value = "";
            tmp = ft_strjoin(result, value);
            free(result);
            result = tmp;
            index = content[close_i] ? close_i + 1 : close_i;
        }
        else if (is_variable_word(content, index))
        {
            new_i = ft_variable_detection(content, index + 1);
            name = malloc_substrcpy(content, index + 1, new_i);
            value = ft_get_env_var_value_with_name(env, name);
            free(name);
            if (!value)
                value = "";
            tmp = ft_strjoin(result, value);
            free(result);
            result = tmp;
            index = new_i + 1;
        }
        else
        {
            start = index;
            while (content[index] && !(is_variable_word(content, index)))
            {
                if (is_backslash(content[index])
                    && ft_is_escaped_double_quote_char(content[index + 1]))
                    index += 2;
                else
                    index++;
            }
            tmp = ft_unescape_double_substr(content, start, index - 1);
            result = ft_strjoin_free_first(result, tmp);
            free(tmp);
        }
    }
    arg = ft_create_arg(result, TOKEN_STRING);
    ft_add_arg_list(cmd, arg);
    free(result);
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
	free(content);
	return (index - 1);
}

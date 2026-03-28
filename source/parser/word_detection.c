#include "../minishell.h"

int		ft_word_detection(t_env *env, char *line, int index)
{
	while (line[index])
	{
		if (is_delimiter(env, line, index))	
			return (index - 1);
		if (is_double_quotes(line[index]))
			index = double_quote_detection(line, index);
		if (is_single_quote(line[index]))
			index = single_quote_detection(line, index);
		index++;
	}
	return (index);
}

int		ft_word_arg_detection(t_env *env, char *line, int index)
{

	while (line[index])
	{
		if (is_word_arg_sep(env, line, index))
			return (index - 1);
		index++;
	}
		return (index - 1);
}

int		ft_file_detection(char *line, int index)
{
	while (line[index])
	{
		if (is_separator(line, index))
		{
			index--;
			if (is_blank(line[index]))
				index--;
			return (index);
		}
		index++;
	}
	return (index);
}

int		ft_blank_detection(char *line, int index)
{
	while (line[index] && is_blank(line[index]))
		index++;
	return (index);
}

int		ft_blank_escape(char *line, int index)
{
	while (line[index])
	{
		if (!(is_blank(line[index])))
			return (index);
		index++;
	}
}

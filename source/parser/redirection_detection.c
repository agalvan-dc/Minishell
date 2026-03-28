#include "../minishell.h"

int		ft_redirection_detection(char *line, int index)
{
	int 	start;

	start = index;
	while (ft_line_isnot_finished(line, index))
	{
		if (!(ft_line_isnot_finished(line, index)))
			return (index - 1);
		index++;
	}
	if (index == ft_strlen(line) && is_redirection(line, index - 1))
		return (index - 1);
	return (start);
}

int		ft_limiter_detection(char *line, int index)
{
	while (line[index])
	{
		if (is_blank(line[index]) || is_separator(line[index]))
			return (index - 1);
		else if (is_double_quote(line[index]))
			index = ft_double_quote_detection(line, index);
		else if (is_single_quote(line[index]))
			index = ft_single_quote_detection(line, index);
		index++;
	}
	return (index - 1);
}



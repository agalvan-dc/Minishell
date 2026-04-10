#include "../../minishell.h"
//review
int		ft_double_quote_detection(char *line, int index)
{
	int		start;

	start = index;
	index += 1;
	while (line[index])
	{
		while (line[index] && is_backslash(line[index]))
			index++;
		if (is_double_quote(line[index]))
			return (index);
		index++;
	}
	return (start);
}

int		ft_single_quote_detection(char *line, int index)
{
	int		start;

	start = index;
	index += 1;
	while (line[index])
	{
		while (line[index] && is_backslash(line[index]))
			index++;
		if (is_single_quote(line[index]))
			return (index);
		index++;
	}
		return (start);
}

char	*ft_get_content_double(char *line, int start, int *index)
{
	char	*content;

	if (is_finish(line[*index]))
		content = ft_get_rest_single_quote(line, start, *index, "\"");
	else
	{
		content = malloc_substrcpy(line, start, *index);	
		(*index)++;
	}
	return (content);
}

char	*ft_get_rest_single_quote(char *line, int start, int end, char *quote)
{
	char	*content;
	char	*heredoc;
	char	*dup;
	
	content = malloc_substrcpy(line, start, end);
	heredoc = ft_heredoc_not_finish(quote);
	dup = malloc_strcpy(content);
	
	free(content);
	content = ft_strjoin(dup, heredoc);

	free(dup);
	free(heredoc);
	return (content);
}

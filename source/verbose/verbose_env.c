#include "../minishell.h"

void	ft_print_line(t_line *line)
{
	ft_printf("Line [%d] : [%s]\n", line->index, line->content);
}

void	ft_print_all_line(t_env *env)
{
	t_line	*line;

	line = ft_get_first_line(env);
	if (!line)
		return ;
	while (line)
	{
		ft_print_line(line);
		line = line->next;
	}
}

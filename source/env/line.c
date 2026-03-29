#include "../minishell.h"

t_line	*ft_init_line(char *content)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->index = -1;
	line->content = content;
	line->prev = NULL;
	line->next = NULL;
	return (line);
}

void	ft_connect_line(t_line	*curr_line, t_line *next_line)
{
	curr_line->next = next_line;
	next_line->prev = curr_line;
}

void    ft_add_line_list(t_env *env, t_line *line)
{
	t_line	*iter;
	int		i;

	i = 1;
	if (!(env->first_line))
	{
		env->first_line = line;
		line->index = i;
	}
	else
	{
		iter = env->first_line;
		i++;
		while (iter->next)
		{
			i++;
			iter = iter->next;
		}
		line->index = i;
		ft_connect_line(iter, line);
	}
}

void	ft_add_line_to_env(t_env *env, char *content)
{
	t_line	*line;

	line = ft_init_line(content);
	ft_add_line_list(env, line);
}

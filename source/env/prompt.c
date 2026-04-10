#include "../../minishell.h"

void	ft_prompt(t_env *env)
{
	char	*read_line;

	while (1)
	{
		ft_use_signal();
		read_line = ft_get_line();
		if (!read_line)
		{
			ft_printf("Exit\n");
			return ;
		}
		if (!(line_is_empty(read_line)))
			ft_execute_line(env, read_line);
		free(read_line);
	}
}

void    ft_write_line(char *line, int fd)
{
    ft_putstr_fd(line, fd);
    ft_putstr_fd("\n", fd);
}

void	ft_create_history(char *line)
{
	int		fd;

	add_history(line);
	fd = open("history.log", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error in history");
	ft_write_line(line, fd);
	close (fd);
}

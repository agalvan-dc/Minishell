/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_prompt(t_env *env)
{
	char	*read_line;

	while (1)
	{
		ft_reset_counter_error(env);
		ft_use_signal();
		read_line = ft_get_line();
		if (!read_line)
		{
			ft_printf("Exit\n");
			return ;
		}
		if (!(line_is_empty(read_line)))
		{
			ft_use_signal_exec();
			ft_execute_line_semicolon(env, read_line);
		}
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
	if (!g_env || !g_env->history_path)
		return ;
	fd = open(g_env->history_path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error in history");
	ft_write_line(line, fd);
	close (fd);
}

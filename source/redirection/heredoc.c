/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

static int	ft_is_limiter(char *line, char *limiter)
{
	if (!line || !limiter)
		return (0);
	if (ft_strlen(line) != ft_strlen(limiter))
		return (0);
	return (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0);
}

static void	ft_heredoc_write_var(t_env *env, char *line, int *i, int fd)
{
	char	*name;
	char	*value;
	int		j;

	if (line[*i + 1] == '?')
	{
		value = ft_get_env_var_value_with_name(env, "?");
		ft_putstr_fd(value ? value : "", fd);
		*i += 2;
		return ;
	}
	j = *i + 1;
	while (line[j] && (ft_isalnum(line[j]) || line[j] == '_'))
		j++;
	name = malloc_substrcpy(line, *i + 1, j - 1);
	value = ft_get_env_var_value_with_name(env, name);
	free(name);
	ft_putstr_fd(value ? value : "", fd);
	*i = j;
}

static void	ft_heredoc_write_line(t_env *env, char *line, int fd, int expand)
{
	int	i;

	if (!expand || !env)
	{
		ft_putstr_fd(line, fd);
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && (line[i + 1] == '?'
				|| ft_isalpha(line[i + 1]) || line[i + 1] == '_'))
			ft_heredoc_write_var(env, line, &i, fd);
		else
			ft_putchar_fd(line[i++], fd);
	}
}

int		ft_compare_line(char *line, char *limiter, int fd_tmp)
{
	if (ft_is_limiter(line, limiter))
	{
		free(line);
		return (1);
	}
	ft_putstr_fd(line, fd_tmp);
	ft_putstr_fd("\n", fd_tmp);
	free(line);
	return (0);
}

char	*ft_heredoc_prompt(t_env *env, char *limiter, int expand)
{
	int		fd_tmp;
	char	*line;
	char	*tmp_file_name;

	tmp_file_name = "tmp.txt";
	fd_tmp = open(tmp_file_name, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd_tmp == -1)
		return (tmp_file_name);
	if (isatty(STDIN_FILENO))
		ft_putstr_fd("heredoc> ", 1);
	line = mini_get_next_line(STDIN_FILENO);
	while (line && !ft_is_limiter(line, limiter))
	{
		ft_heredoc_write_line(env, line, fd_tmp, expand);
		ft_putstr_fd("\n", fd_tmp);
		free(line);
		if (isatty(STDIN_FILENO))
			ft_putstr_fd("heredoc> ", 1);
		line = mini_get_next_line(STDIN_FILENO);
	}
	free(line);
	close(fd_tmp);
	return (tmp_file_name);
}

char    *ft_read_and_extract_content_file(char *path)
{
	int		fd;
	char	*buf;
	ssize_t	bytes;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = ft_calloc(BUFF_SIZE, sizeof(char));
	if (!buf)
	{
		close(fd);
		return (NULL);
	}
	bytes = read(fd, buf, BUFF_SIZE - 1);
	close(fd);
	if (bytes == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[bytes] = '\0';
	return (buf);
}

char	*ft_heredoc_not_finish(char *limiter)
{
	int		fd_tmp;
	char	*line;
	char	*content;

	fd_tmp = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (isatty(STDIN_FILENO))
		ft_putstr_fd("finish_quote> ", 1);
	line = mini_get_next_line(STDIN_FILENO);
	while (line && !ft_compare_line(line, limiter, fd_tmp))
	{
		if (isatty(STDIN_FILENO))
			ft_putstr_fd("finish_quote> ", 1);
		line = mini_get_next_line(STDIN_FILENO);
	}
	close(fd_tmp);
	content = ft_read_and_extract_content_file("tmp.txt");
	unlink("tmp.txt");
	return (content);
}

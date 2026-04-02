#include "../minishell.h"

int		ft_compare_line(char *line, char *limiter, int fd_tmp)
{
	if (ft_strncmp(line, limiter, ft_strlen(limiter)))
	{
		free(line);
		return (1);
	}
	else
	{
		ft_putstr_fd(line, fd_tmp);
		free(line);
		return (0);
	}
}

char	*ft_heredoc_prompt(char *limiter)
{
	int		fd_tmp;
	char	*line;
	char	*tmp_file_name;

	tmp_file_name = "tmp.txt";
	fd_tmp = open(tmp_file_name, O_CREAT | O_WRONLY, 0777);
	ft_putstr_fd("heredoc> ", 1);
	line = mini_get_next_line(STDIN_FILENO);
	while (line && !ft_compare_line(line, limiter, fd_tmp))
	{
		ft_putstr_fd("heredoc> ", 1);
		line = ft_mini_get_next_line(STDIN_FILENO);
	}
	close(fd_tmp);
	unlink("tmp.txt");
	return (tmp_file_name);
}

char    *ft_read_and_extract_content_file(char *path)
{
	int		fd;
	char	*buf;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = ft_calloc(BUFF_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	else
		free(buf);
	return (NULL);
}

char	*ft_heredoc_not_finish(char *limiter)
{
	int		fd_tmp;
	char	*line;
	char	*content;

	fd_tmp = open("tmp.txt", O_CREAT | O_WRONLY, 0777);
	ft_putstr_fd("finish_quote> ", 1);
	line = mini_get_next_line(STDIN_FILENO);
	while (line && !ft_compare_line(line, limiter, fd_tmp))
	{
		ft_putstr_fd("finish_quote> ", 1);
		line = ft_mini_get_next_line(STDIN_FILENO);
	}
	close(fd_tmp);
	content = ft_read_and_extract_content_file("tmp.txt");
	unlink("tmp.txt");
	return (content);
}

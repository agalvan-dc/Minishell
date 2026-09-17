/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void	ft_execute_line(t_env *env, char *line)
{
	ft_parsing(env, line);
	ft_check_error_parsing(env);

	if (ft_doesnt_have_error_parsing(env) == 1)
	{
		ft_processing_cmd(env);
		ft_processing_redir(env);
		if (ft_doesnt_have_error_processing(env) == 1)
			ft_execution(env);
	}
	ft_reset_counter_error(env);
	ft_remove_all_token(env);
}

void	ft_execute_line_semicolon(t_env *env, char *line)
{
	int		i;
	int		start;
	char	quote;
	char	*sub;

	i = 0;
	start = 0;
	quote = 0;
	while (1)
	{
		if (line[i] == '\0' || (quote == 0 && line[i] == ';'))
		{
			if (i > start)
			{
				sub = malloc_substrcpy(line, start, i - 1);
				if (sub && !(line_is_empty(sub)))
					ft_execute_line(env, sub);
				free(sub);
			}
			if (line[i] == '\0')
				break ;
			start = i + 1;
		}
		else if (quote == 0 && is_quote(line[i]))
			quote = line[i];
		else if (quote != 0 && line[i] == quote)
			quote = 0;
		i++;
	}
}

void	ft_execute_multi_line(t_env *env, t_line *line)
{
	while (line)
	{
		ft_execute_line(env, line->content);
		line = line->next;
	}
}

void	ft_parse_line_with_semicolon(t_env *env, char *line)
{
	int		index;
	int		start;
	int		end;
	char	*sub_line;

	index = 0;
	start = index;
	while (line[index])
	{
		if (line[index] == ';' || is_finish(line[index + 1]))
		{
			if (is_finish(line[index + 1]))
				end = index;
			else
				end = index - 1;
			sub_line = ft_substr(line, start, end);
			ft_add_line_to_env(env, sub_line);
		}
		index++;
	}
}

int		ft_env_have_multi_line(t_env *env)
{
	t_line	*line;
	int		nb;

	line = ft_get_first_line(env);
	nb = 1;
	while (line)
	{
		nb++;
		line = line->next;
	}
	if (nb > 1)
		return (1);
	return (0);
}

char	*ft_get_line(void)
{
	struct	termios saved;
	struct	termios	attributes;
	char	*line;

	ft_bzero(&saved, sizeof(saved));
	ft_bzero(&attributes, sizeof(attributes));
	tcgetattr(STDIN_FILENO, &saved);
	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
	line = readline("[Minishell]$ ");
	if (is_null(line))
	{
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
		return (NULL);
	}
	ft_create_history(line);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &saved);
	return (line);
}

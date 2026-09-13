/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirect.c                                    :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

t_redir		*ft_init_redir(int type, char *content)
{
	t_redir		*redir;

	redir = (t_redir *)ft_calloc(1, sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->content = content;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	return (redir);
}

t_redir		*ft_init_heredoc(int type, char *content, char *limiter)
{
	t_redir     *redir;

	redir = (t_redir *)ft_calloc(1, sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->content = content;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->delimiter = limiter;
	return (redir);
}

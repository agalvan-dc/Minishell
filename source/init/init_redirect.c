#include "../minishell.h"

t_redir		*ft_init_redir(int type, char *content)
{
	t_redir		*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->content = content;
	redir->fd_in = STDIN_FILENO;
	redir->fd_out = STDOUT_FILENO;
	redir->limiter = NULL;
	redir->tmp_file = NULL;
	return (redir);
}

t_redir		*ft_init_heredoc(int type, char *content, char *limiter)
{
    t_redir     *redir;

    redir = (t_redir *)malloc(sizeof(t_redir));
    if (!redir)
        return (NULL);
    redir->type = type;
    redir->content = content;
    redir->fd_in = STDIN_FILENO;
    redir->fd_out = STDOUT_FILENO;
    redir->limiter = limiter;
    redir->tmp_file = NULL;
    return (redir);
}

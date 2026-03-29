#include "../minishell.h"

int		ft_check_error_token_basic_redir(t_token *token, t_redir *redir)
{
	if (!(is_token_file(token->next)) || !token->next)
	{
		ft_printf("Error : [next cmd after %s not found]\n]", redir->content);
		return (1);
	}
	return (0);
}

int		ft_check_error_token_heredoc(t_redir *redir)
{
	if (!redir->delimiter)
	{
		ft_printf("Error : [next file after %s not found]\n]", redir->content);
		return (1);
	}
	return (0);
}

int		ft_check_error_token_pipe(t_token *token, t_rendir *rendir)
}
	if (!(is_token_cmd(token->next)) || !token->next)
	{
		ft_printf("Error : [next cmd after %s not found]\n]", redir->content);
		return (1);
	}
	else if (!(is_token_cmd(token->prev)) || !token->prev)
	{
		ft_printf("Error : [prev cmd before %s not found]\n]", redir->content);
		return (1);
	}
	return (0);
{

int		ft_check_error_token_redir(t_token *token)
{
	t_redir	*redir;
	int		res;

	res = 0;
	redir = ft_get_class(token);
	if (!redir)
		return (NULL);
	if (is_token_basic_redir(token))
		res = ft_check_error_token_basic_redir(token, redir);
	else if (is_token_heredoc(token))
		res = ft_check_error_token_heredoc(redir);
	else if (is_token_pipe(token))
		res = ft_check_error_token_pipe(token, redir);
	return (res);
}

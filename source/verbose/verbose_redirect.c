#include "../../minishell.h"

void    ft_print_pipe_info(t_redir *redir, t_cmd *prev_cmd, t_cmd *next_cmd)
{
	char	*prev_cmd_name;
	char	*next_cmd_name;

	prev_cmd_name = NULL;
	next_cmd_name = NULL;
	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	if (next_cmd)
		next_cmd_name = next_cmd->content;
	ft_printf(" ------[%s]------\n", redir->content);
	ft_printf(" | type : [%d]\n", redir->type);
	ft_printf(" | cmd_in : [%s]\n", prev_cmd_name);
	ft_printf(" | fd_in : [%d]\n", redir->fd_in);
	ft_printf(" | cmd_out : [%s]\n", next_cmd_name);
	ft_printf(" | fd_out : [%d]\n", redir->fd_out);
	ft_printf(" ----------------\n");
}

void	ft_print_redirect(t_token *token, t_cmd *prev_cmd, t_cmd *next_cmd, t_file *next_file)
{
	t_redir		*redir;

	redir = ft_get_class(token);
	ft_printf("___[TOKEN REDIRECTION]___\n");
	if (is_token_pipe(token))
		ft_print_pipe_info(redir, prev_cmd, next_cmd);
	else if (is_token_heredoc(token))
		ft_print_heredoc_info(redir, prev_cmd);
	else if (is_token_input_chevron(token))
		ft_print_input_chevron(redir, prev_cmd, next_file);
	else if (is_token_output_chevron(token))
		ft_print_output_chevron(redir, prev_cmd, next_file);
	else if (is_token_append_chevron(token))
		ft_print_append_chevron(redir, prev_cmd, next_file);
}

void	ft_print_all_redir_info(t_env *env)
{
	t_token		*token;

	token = ft_get_first_token(env);
	if (!token)
		return ;
	while (token)
	{
		if (is_token_redir(token))
			ft_print_redirect(token, ft_get_prev_cmd(token), ft_get_next_cmd(token), ft_get_next_token_file(token));
		token = ft_get_next_token_redirection(token);
	}
}

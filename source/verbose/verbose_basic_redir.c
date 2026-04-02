#include "../minishell.h"

void    ft_print_heredoc_info(t_redir *redir, t_cmd *prev_cmd)
{
	char	*prev_cmd_name;

	if (prev_cmd)
		prev_cmd_name = prev_cmd->content;
	else
		prev_cmd_name = NULL;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | LIMITER : [%s]\n", redir->limiter);
	printf(" ----------------\n");
}

void	ft_print_input_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file)
{
	char	*prev_cmd_name;
	char	*next_file_name;

	prev_cmd_name = NULL;
	next_file_name = NULL;
	if (prev_cmd)
        prev_cmd_name = prev_cmd->content;  
	if (next_file)	
		next_file_name = next_file->name;
	printf(" ------[%s]------\n", redir->content);
	printf(" | type : [%d]\n", redir->type);
	printf(" | cmd_in : [%s]\n", prev_cmd_name);
	printf(" | fd_in : [%d]\n", redir->fd_in);
	printf(" | next_file : [%s]\n", next_file_name);
	printf(" | fd_file : [%d]\n", next_file->fd);
	printf(" ----------------\n");
}

void	ft_print_output_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file)
{
	 char    *prev_cmd_name;
    char    *next_file_name;

    prev_cmd_name = NULL;
    next_file_name = NULL;
    if (prev_cmd)
        prev_cmd_name = prev_cmd->content;
    if (next_file)
        next_file_name = next_file->name;
    printf(" ------[%s]------\n", redir->content);
    printf(" | type : [%d]\n", redir->type);
    printf(" | cmd_in : [%s]\n", prev_cmd_name);
    printf(" | fd_in : [%d]\n", redir->fd_in);
    printf(" | next_file : [%s]\n", next_file_name);
    printf(" | fd_file : [%d]\n", next_file->fd);
    printf(" ----------------\n");

}

void	 ft_print_append_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file)
{
	char    *prev_cmd_name;
    char    *next_file_name;

    prev_cmd_name = NULL;
    next_file_name = NULL;
    if (prev_cmd)
        prev_cmd_name = prev_cmd->content;
    if (next_file)
        next_file_name = next_file->name;
    printf(" ------[%s]------\n", redir->content);
    printf(" | type : [%d]\n", redir->type);
    printf(" | cmd_in : [%s]\n", prev_cmd_name);
    printf(" | fd_in : [%d]\n", redir->fd_in);
    printf(" | next_file : [%s]\n", next_file_name);
    printf(" | fd_file : [%d]\n", next_file->fd);
    printf(" ----------------\n");
}

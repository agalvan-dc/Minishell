#include "../../minishell.h"

t_token		*ft_init_token(void)
{
	t_token		*token;

	token = (t_token *)malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->id = 0;
	token->class = NULL;
	token->next = NULL;
	token->prev = NULL;
	return (token);
}

t_arg		*ft_init_arg(char *content, int id)
{
	t_arg	*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->id = id;
	arg->content = content;
	arg->next = NULL;
	arg->prev = NULL;
	return (arg);
}

t_blank		*ft_init_blank(char *content, int id)
{
	t_blank		*blank;

	blank = (t_blank *)malloc(sizeof(t_blank));
	if (!blank)
		return (NULL);
	blank->content = content;
	blank->id = id;
	return (blank);
}

t_word		*ft_init_word(char *content, int id)
{
	t_word		*word;

	word = (t_word *)malloc(sizeof(t_word));
	if (!word)
		return (NULL);
	word->content = content;
	word->id = id;
	return (word);
}

t_cmd		*ft_init_cmd(char *content, int id)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->id = id;
	cmd->content = content;
	cmd->flags = NULL;
	cmd->bin = NULL;
	cmd->arg = NULL;
	cmd->args = NULL;
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	cmd->first_arg = NULL;
	cmd->pid = 0;
	return (cmd);
}

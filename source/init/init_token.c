#include "../../minishell.h"

t_token		*ft_init_token(void)
{
	t_token		*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	return (token);
}

t_arg		*ft_init_arg(char *content, int id)
{
	t_arg	*arg;

	arg = (t_arg *)ft_calloc(1, sizeof(t_arg));
	if (!arg)
		return (NULL);
	arg->id = id;
	if (content)
	    arg->content = ft_strdup(content);
	else
	    arg->content = ft_strdup("");
	return (arg);
}

t_blank		*ft_init_blank(char *content, int id)
{
	t_blank		*blank;

	blank = (t_blank *)ft_calloc(1, sizeof(t_blank));
	if (!blank)
		return (NULL);
	blank->content = ft_strdup(content);
	blank->id = id;
	return (blank);
}

t_word		*ft_init_word(char *content, int id)
{
	t_word		*word;

	word = (t_word *)ft_calloc(1, sizeof(t_word));
	if (!word)
		return (NULL);
	word->content = ft_strdup(content);
	word->id = id;
	return (word);
}

t_cmd		*ft_init_cmd(char *content, int id)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->id = id;
	cmd->content = ft_strdup(content);
	cmd->fd_in = STDIN_FILENO;
	cmd->fd_out = STDOUT_FILENO;
	return (cmd);
}

#include "../minishell.h"

t_token	*ft_create_token_word(char *content, int id)
{
	t_token		*token;
	
	token = ft_init_token();
	token->id = id;
	token->class = init_word(content, id);
	return (token);
}

t_arg	*ft_create_arg(char *content, int id)
{
	t_arg	*arg;

	arg = ft_init_arg(content, id);
	return (arg);
}

t_token	*ft_create_token_redir(char *content, int index, int new_i)
{
	char	*line;
	int		type;
	t_token	*token;

	line = ft_substr(content, index, new_i);
	type = ft_type_of_redirect(content);
	token = ft_init_token();
	token->id = type;
	token->class = ft_init_redir(type, content);
	return (token);
}

t_token	*ft_create_token_cmd(char *content, int id)
{
	t_token	*token;

	token = ft_init_token();
	token->id = id;
	token->class = ft_init_cmd(content, id);
	return (token);
}

t_token	*ft_create_token_file(char *name, int fd, int id)
{
	t_token	*token;
	
	token = ft_init_token();
	token->id = id;
	token->class = ft_init_file(name, fd);
	return (token);
}

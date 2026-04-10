#include "../../minishell.h"

t_token		*ft_word_tokenizer(char *content, int id)
{
	t_token	*token;

	token = ft_create_token_word(content, id);
	return (token);
}

void	ft_word_arg_tokenizer(t_env *env, t_cmd *cmd, char *content)
{
	t_arg	*arg;

	if (is_valid_variable(env, content))
		arg = ft_create_arg(content, TOKEN_VARIABLE);
	else
		arg = ft_create_arg(content, TOKEN_WORD);
	ft_add_arg_list(cmd, arg);
}

t_token		*ft_file_tokenizer(char *name, int id)
{
	t_token	*token;
	int		fd;

	fd = open(name, O_RDONLY | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
		ft_printf("%s : so such file or directory\n", name);
	token = ft_create_token_file(name, fd, id);
	close (fd);
	return (token);
}

int		ft_next_file_tokenizer(t_env *env, char *line, int index)
{
	t_token	*token;
	int		new_index;
	char	*content;

	if (line_is_finish(line, index))
		return (index);
	index = ft_blank_escape(line, index);
	new_index = ft_file_detection(line, index);
	content = malloc_substrcpy(line, index, new_index);
	token = ft_file_tokenizer(content, TOKEN_FILE);
	ft_add_token_list(env, token);
	return (new_index);
}

int		ft_blank_arg_tokenizer(t_env *env, t_cmd *cmd, char *line, int index)
{
	t_arg	*arg;
	int		start;
	int		end;

	end = index;
	start = index;
	while (line[index])
	{
		if (!(is_blank_arg(env, line, index)))
		{
			end = index - 1;
			break ;
		}
		index++;
	}
	arg = ft_arg_tokenizer(line, start, end, TOKEN_BLANK);
	ft_add_arg_list(cmd, arg);
	return (end);
}

#include "../../minishell.h"

int		ft_arg_extraction(t_env *env, t_cmd *cmd, char *line, int index)
{
	int		new_index;

	new_index = 0;
	if (is_flags(line, index))
	{
		new_index = ft_flags_tokenizer(env, cmd, line, index);
		index = new_index;
	}
	while (!(line_is_finish(line, index)) && !(is_separator(line, index)))
	{
		index = ft_blank_detection(line, index);
		new_index = ft_arg_classification(env, cmd, line, index);
		index = new_index;
		index++;
	}
	return (new_index);
}

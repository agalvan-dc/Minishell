#include "../../minishell.h"

int		ft_type_of_redirect(char *content)
{
	if (is_pipe(content, 0))
		return (TOKEN_PIPE);
	else if (is_input_chevron(content, 0))
		return (TOKEN_INPUT_CHEVRON);
	else if (is_output_chevron(content, 0))
		return (TOKEN_OUTPUT_CHEVRON);
	else if (is_append_chevron(content, 0))
		return (TOKEN_APPEND_CHEVRON);
	else if (is_heredoc(content, 0))
		return (TOKEN_HEREDOC);
	return (0);
}

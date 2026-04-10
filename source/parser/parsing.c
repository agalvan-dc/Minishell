#include "../../minishell.h"

void	ft_parsing(t_env *env, char *line)
{
	ft_tokenization(env, line);
	if (env->verbose == 1)
		ft_print_chained_list(env);
	return ;
}

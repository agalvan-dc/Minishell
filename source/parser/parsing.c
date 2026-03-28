#include "../minishell.h"

void	ft_parsing(t_env *env, char *line)
{
	tokenization(env, line);
	if (env->verbose == 1)
		print_chained_list(env);
	return ;
}

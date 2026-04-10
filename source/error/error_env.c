#include "../../minishell.h"

void	ft_reset_counter_error(t_env *env)
{
	env->error_parsing = 0;
	env->error_processing = 0;
}

int		ft_doesnt_have_error_parsing(t_env *env)
{
	if (env->error_parsing < 1)
		return (1);
	return (0);
}

int		ft_doesnt_have_error_processing(t_env *env)
{
	if (env->error_processing < 1)
		return (1);
	return (0);
}

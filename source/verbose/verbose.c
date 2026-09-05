#include "../../minishell.h"

void	ft_ask_verbose(t_env *env)
{
	int	boo;
	char	answer;

	ft_printf("Minishell mode verbose [Y/N] ?");
	boo = read(0, &answer, 1);
	if (boo == -1)
		return ;
	if (answer == 'Y' || answer == 'y')
	{
		ft_printf("--- Minishell mode verbose activate ---\n");
		env->verbose = 1;
	}
	else if (answer == 'N' || answer == 'n')
		env->verbose = 0;
}

#include "minishell.h"

t_env	*g_env;

int		main(int argc, char **argv, char **env_var)
{
	t_env	*g_env;
	char	**env_variable;

	(void)argc;
	(void)argv;

	env_variable = malloc_strcpy_array(env_variable);
	env = init_env(env_variable);
	ask_verbose(env);	
	prompt(env);
	remove_all(env);
}

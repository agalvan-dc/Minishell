#include "minishell.h"

t_env	*g_env;

int		main(int argc, char **argv, char **env_var)
{
	char	**env_variable;

	(void)argc;
	(void)argv;

	env_variable = malloc_strcpy_array(env_var);
	g_env = ft_init_env(env_variable);
	ft_ask_verbose(g_env);	
	ft_prompt(g_env);
	ft_remove_all(g_env);
}

/*
int     main(int argc, char **argv, char **env_var)
{
    char    **env_variable;

    (void)argc;
    (void)argv;
    fprintf(stderr, "DEBUG env_var[0]: %s\n", env_var[0]);
    env_variable = malloc_strcpy_array(env_var);
    g_env = ft_init_env(env_variable);
    t_var *v = g_env->first_var;
    while (v)
    {
        fprintf(stderr, "VAR: [%s]=[%s]\n", v->name, v->value);
        v = v->next;
    }
    ft_ask_verbose(g_env);
    ft_prompt(g_env);
    ft_remove_all(g_env);
    return (0);
}*/

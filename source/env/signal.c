#include "../../minishell.h"

void    ft_call_prompt(int key)
{
	(void)key;
	rl_replace_line("", 0);
	rl_on_new_line();
	write(1, "\n", 1);
	rl_redisplay();
	ft_update_var_status_process(g_env, 130);
}

void	ft_pass(int key)
{
	(void)key;
	rl_redisplay();
}

void	ft_exit_prompt(int key)
{
	(void)key;
	printf("Exit...\n");
	exit(0);
}

void	ft_add_signal_env_var(t_env *env)
{
	t_var	*signal_var;
	char	*value;
	char	*name;

	name = malloc_strcpy("?");
	value = malloc_strcpy("0");
	signal_var = ft_init_env_var(name, value, VALUE);
	ft_add_new_env_var(env, signal_var);
}

void    ft_use_signal(void)
{
    signal(SIGQUIT, ft_pass);
    signal(SIGINT, ft_call_prompt);
}

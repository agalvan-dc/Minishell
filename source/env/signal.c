/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

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

void	ft_sigint_handler(int sig)
{
	(void)sig;
	ft_update_var_status_process(g_env, 130);
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_use_signal(void)
{
	struct sigaction	sa;

	rl_catch_signals = 0;
	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = ft_sigint_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_use_signal_exec(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
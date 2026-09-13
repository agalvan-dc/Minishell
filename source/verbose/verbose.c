/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

static int	is_yes_answer(char *answer)
{
	if (answer[0] == 'Y' || answer[0] == 'y')
		return (1);
	return (0);
}

void	ft_ask_verbose(t_env *env)
{
	char	*answer;

	if (!isatty(STDIN_FILENO))
		return ;
	ft_printf("Minishell mode verbose [Y/N] ? ");
	answer = readline(NULL);
	if (!answer)
		return ;
	if (is_yes_answer(answer))
	{
		ft_printf("--- Minishell mode verbose activate ---\n");
		env->verbose = 1;
	}
	free(answer);
}

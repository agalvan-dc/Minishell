/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalvan- <agalvan-@student.42.es>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 08:58:22 by agalvan-          #+#    #+#             */
/*   Updated: 2026/09/14 08:58:26 by agalvan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_env;

int		main(int argc, char **argv, char **env_var)
{
	char	**env_variable;

	env_variable = malloc_strcpy_array(env_var);
	g_env = ft_init_env(env_variable);
	ft_ask_verbose(g_env, argc, argv);
	ft_prompt(g_env);
	ft_remove_all(g_env);

	return (0);
}


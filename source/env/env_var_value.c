/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_value.c                                    :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

void    ft_change_env_var_value(t_var *var, char *new_value)
{
	if (var->value)
		free(var->value);
	var->value = new_value;
	var->id = VALUE;
}

void	ft_change_env_var_value_with_name(t_env *env, char *name, char *value)
{
	t_var	*var;

	var = ft_get_env_var_with_name(env, name);
	if (!var)
		return ;
	ft_change_env_var_value(var, value);
}

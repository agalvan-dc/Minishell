#include "../../minishell.h"

void	ft_disconnect_args(t_arg *curr_arg)
{
	t_arg	*arg_next;
	t_arg	*arg_prev;

	arg_prev = curr_arg->prev;
	arg_next = curr_arg->next;
	if (arg_prev)
		arg_prev->next = arg_next;
	if (arg_next)
		arg_next->prev = arg_prev;
	curr_arg->next = NULL;
	curr_arg->prev = NULL;
}

void	ft_disconnect_line(t_line *curr_line)
{
	t_line	*next_line;
	t_line	*prev_line;

	prev_line = curr_line->prev;
	next_line = curr_line->next;
	if (prev_line)
		prev_line->next = next_line;
	if (next_line)
		next_line->prev = prev_line;
	curr_line->next = NULL;
	curr_line->prev = NULL;
}

void    ft_disconnect_env_var_first(t_env *env, t_var *var, t_var *var_next)
{
	if (!var->next)
		env->first_var = NULL;
	else
	{
		env->first_var = var_next;
		var_next->prev = NULL;
	}
	var->next = NULL;
	var->prev = NULL;
}

void	ft_disconnect_env_var(t_env *env, t_var *var)
{
	t_var	*var_prev;
	t_var	*var_next;

	var_prev = var->prev;
	var_next = var->next;

	if (var->index == 0)
	{
		ft_disconnect_env_var_first(env, var, var_next);
		return ;
	}
	if (var_prev)
		var_prev->next = var_next;
	if (var_next)
		var_next->prev = var_prev;
	var->next = NULL;
	var->prev = NULL;
}

void	ft_disconnect_token(t_token *token)
{
	token->next = NULL;
	token->prev = NULL;
}

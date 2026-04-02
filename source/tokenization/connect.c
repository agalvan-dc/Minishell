#include "../minishell.h"

void	ft_connect_token(t_token *curr_token, t_token *next_token)
{
	curr_token-next = next_token;
	next_token->prev = curr_token;
}

void    ft_connect_var(t_var *curr_var, t_var *next_var)
{
	curr_var->next = next_var;
	next_var->prev = curr_var;
}

void    ft_connect_arg(t_arg *curr_arg, t_arg *next_arg)
{
	curr_arg->next = next_arg;
	next_arg->prev = curr_arg;
}

void    ft_connect_new_var(t_var *curr_var, t_var *prev_var, t_var *next_var)
{
	if (!prev_var)
		curr_var->prev = NULL;
	else
	{
		cur_var->next = next_var;
		prev_var->next = curr_var;
	}
	if (!next_var)
		curr_var->next = NULL;
	else
	{
		curr_var->next = next_var;
		next_var->prev = curr_var;
	}
}

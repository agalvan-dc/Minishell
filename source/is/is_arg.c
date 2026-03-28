#include "../minishell.h"

int		is_arg_variable(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_VARIABLE)
		return (1);
	return (0);
}

int		is_arg_flags(t_arg *arg)
{
	if(!arg)
		return (0);
	if (arg->id == TOKEN_FLAGS)
		return (1);
	return (0);
}

int		is_arg_blank(t_arg *arg)
{
	if (!arg)
		return (0);
	if (arg->id == TOKEN_BLANK)
		return (1);
	return (0);
}

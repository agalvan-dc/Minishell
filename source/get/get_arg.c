#include "../minishell.h"

t_arg	*ft_get_first_arg(t_cmd *cmd)
{
	if (cmd->first_arg)
		return (cmd->first_arg);
	return (NULL);
}

char	**ft_get_cmd_args(t_cmd *cmd)
{
	if (cmd->args)
		return (cmd->args);
	return (NULL);
}

int		ft_get_number_args(t_cmd *cmd)
{
	t_arg	*arg;
	int		i;

	i = 0;
	if (!(cmd_have_args(cmd)))
		return (0);
	arg = ft_get_first_arg(cmd);
	if (!arg)
		return (0);
	while (arg)
	{
		i += 1;
		arg->next;
	}
	return (i);
}

t_arg	*ft_get_cmd_flags(t_cmd *cmd)
{
	t_arg	*arg;
	if (!(cmd_have_args(cmd)))
		return(NULL);
	arg = ft_get_first_arg(cmd);
	if (!arg)
		return (NULL);
	while (arg)
	{
		if (is_arg_flags(arg))
			return(arg);
		arg = arg->next;
	}
	return(NULL);
}

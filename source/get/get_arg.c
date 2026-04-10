#include "../../minishell.h"

t_arg	*ft_get_first_arg(t_cmd *cmd)
{
	if (cmd->first_arg)
		return (cmd->first_arg);
	return (NULL);
}

char	**ft_get_cmd_args(t_cmd *cmd)
{
	if (!cmd->args)
		cmd->args = ft_build_cmd_args(cmd);
	return (cmd->args);
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
		arg = arg->next;
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

char	**ft_build_cmd_args(t_cmd *cmd)
{
	t_arg	*arg;
	char	**args;
	int		count;
	int		i;	

	fprintf(stderr, "ft_build_cmd_args: first_arg=%p count=%d\n", 
		cmd->first_arg, ft_get_number_args(cmd));
	count = ft_get_number_args(cmd);
	if (count == 0)
		return (NULL);
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	arg = cmd->first_arg;
	i = 0;
	while (arg)
	{
		args[i] = ft_strdup(arg->content);
		arg = arg->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}

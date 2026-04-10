#include "../../minishell.h"

int		ft_size_of_cmd_list(t_cmd *cmd)
{
	t_arg	*arg;
	int		i;

	i = 0;
	arg = ft_get_first_arg(cmd);
	while (arg)
	{
		i++;
		arg = arg->next;
	}
	return (i);
}

int		ft_size_of_var_list(t_env *env)
{
	t_var	*var;
	int		i;

	i = 0;
	var = ft_get_first_env_var(env);
	while (var)
	{
		i++;
		var = var->next;
	}
	return (i);
}

char	**ft_cmd_list_to_array(t_cmd *cmd)
{
	t_arg	*arg;
	char	**complete;
	int		i;

	i = 0;
	if (!(cmd->first_arg))
		return (NULL);
	arg = ft_get_first_arg(cmd);
	if (!(arg->content))
		return (NULL);
	complete = malloc(sizeof(char *) * (ft_size_of_cmd_list(cmd) + 1));
	if (!complete)
		return (NULL);
	while (arg)
	{
		complete[i] = malloc_strcpy(arg->content);
		if (!(complete[i]))
		{
			while (i > 0)
			{
				free(complete[i]);
				i--;
			}
			return (NULL);
		}
		arg = arg->next;
		i++;
	}
	ft_remove_all_arg(cmd);
	complete[i] = NULL;
	return (complete);
}

char	**ft_var_list_to_array(t_env *env)
{
	t_var	*var;
	char	**complete;
	int		i;

	i = 0;
	if (!(env->first_var))
		return (NULL);
	var = ft_get_first_env_var(env);
	if (!var)
		return (NULL);
	complete = malloc(sizeof(char *) * (ft_size_of_var_list(env) + 1));
	if (!complete)
		return (NULL);
	while (var)
	{
		if (!var->value)
			complete[i] = ft_strjoin_char(var->name, "", '=');
		else
			complete[i] = ft_strjoin_char(var->name, var->value, '=');
		var = var->next;
		i++;
	}
	complete[i] = NULL;
	return (complete);
}

char	*ft_cmd_list_to_str(t_cmd *cmd)
{
	t_arg	*arg;
	char	*complete;

	if (!(cmd_have_args(cmd)))
		return (NULL);
	arg = ft_get_first_arg(cmd);
	if (!(arg->content))
		return (NULL);
	complete = malloc_strcpy(arg->content);
	arg = arg->next;
	while (arg)
	{
		complete = ft_strjoin_free_first(complete, arg->content);
		arg = arg->next;
	}
	ft_remove_all_arg(cmd);
	return (complete);
}

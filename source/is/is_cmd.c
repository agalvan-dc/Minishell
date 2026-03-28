#include "../minishell.h"

int		is_exit(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("exit", cmd->content)
		return (1);
	return(0);
}

int		is_unset(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("unset", cmd->content))
		return (1);
	return (0);
}

int		is_bin(t_env *env, char *word)
{
	char	**bins;

	bins = get_env_bins(env);
	if (!bins)
		return (0);
	if (test_absolute_bin_acces(word) || test_bin_acces(bins, word))
	{
		free_array(bins);
		return (1);
	}
	free_array(bins);
	return (0);
}

int		is_cmd(t_env *env, char *word)
{
	if (is_bin(env, word) || is_builtin(word))	
		return (1);
	return (0);
}

int		is_builtin(char *content)
{
	if (!content)
		return (0);
	if (is_same_name(content, "cd"))
		return (1);
	if (is_same_name(content, "pwd"))
		return (1);
	if (is_same_name(content, "echo"))
		return (1);
	if (is_same_name(content, "exit"))
		return (1);
	if (is_same_name(content, "unset"))
		return (1);
	if (is_same_name(content, "env"))
		return (1);
	if (is_same_name(content, "export"))
		return (1);
	return (0);
}

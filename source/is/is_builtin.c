#include "../../minishell.h"

int		is_echo (t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("echo", cmd->content))
		return (1);
	return (0);
}

int		is_pwd(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("pwd", cmd->content))
		return (1);
	return (0);
}

int		is_export(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("export", cmd->content))
		return (1);
	return (0);
}

int		is_cd(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("cd", cmd->content))
		return (1);
	return (0);
}

int		is_env(t_cmd *cmd)
{
	if (!cmd)
		return (0);
	if (is_same_name("env", cmd->content))
		return (1);
	return (0);
}

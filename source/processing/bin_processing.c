#include "../minishell.h"

char	**ft_append_bin_name_in_args(char **args, char *name)
{
	char	**new_args;

	if (!args)
		ft_str_to_array(name);
	else
	{
		new_args = ft_arrayjoin_str(args, name, 0);
		free(args);
	}
	return (new_args);
}

char	*ft_extract_bin_name_in_path(char *path)
{
	int		index;
	char	*name;

	index = ft_strlen(path);
	while (index > 0 && path[index] != '/')
		i--;
	name = ft_malloc_strcpy_after_index(path, index + 1);
	if (!name)
		return (NULL);
	return (name);
}

void	ft_setup_bin_path(t_cmd *cmd, char **bins)
{
	char	*cmd;
	char	*path;

	cmd = cmd->content;
	if (ft_test_bin_acces(bins, cmd))
	{
		path = ft_create_path_bin(bins, cmd);
		cmd->bin = path;
		return ;
	}
	else if (ft_test_absolute_bin_access(cmd))
		cmd->bin = ft_malloc_strcpy(cmd);
	return ;
}

void	ft_setup_bin_args(t_cmd *cmd, char **bins)
{
	char	*command;

	command = cmd->content;
	if (ft_test_bin_acces(bins, command))
	{
		cmd->args = ft_append_bin_name_in_args(cmd->args, cmd->content);
		return ;
	}
	else if (ft_test_absolute_bin_access(command))
	{
		command = ft_extract_bin_name_in_path(command);
		free(cmd->content);
		cmd->content = command;
		cmd->args = ft_append_bin_name_in_args(cmd->args, cmd->content);
		return ;
	}
}

char	*ft_create_path_bin(char **bins, char *cmd)
{
	char	*path;
	int		i;

	i = 0;
	while (bins[i])
	{
		path = ft_strjoin_char(bins[i], cmd, '/');
		if (acces(path, X_OK & F_OK) == 0)
			return (path);
		i++;
	}
	return (NULL);
}

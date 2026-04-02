#include "../minishell.h"

char	**ft_get_list_of_bins(t_env *env)
{
	char	**bins;
	char	*path;

	path = ft_get_env_var_value_with_name(env, "PATH");
	bins = ft_split(path, ':');
	return (bins);
}

int		ft_test_bin_access(char **bins, char *word)
{
	int		i;
	char	*path;

	i = 0;
	while (bins[i])
	{
		path = ft_strjoin_char(bins[i], word, '/');
		if (access(path X_OK & F_OK) == 0)
		{
			free(path);
			return (1);
		}
	}
	return (0);
}

int		ft_test_absolute_bin_access(char *path)
{
	if (access(path, X_OK & F_OK) == 0)
		return (1);
	return (0);
}

#include "../minishell.h"

int		is_variable_word(char *s, int i)
{
	if (s[i] == '$' && !(is_blank(s[i + 1])) && !(is_finish(s[i + 1]))
	!(is_quote(s[i + 1])) && !(is_separator(s, i + 1)))
		return (1);
	return (0);
}

int		variable_exist(t_env *env, char *name)
{
	if(get_env_var_value_with_name(env, name) != NULL)
		return (1);
	return (0);
}

char	*var_name_extraction(char *s, int i)
{
	int		start;
	int		end;


	end = i;
	start = i;
	if (s[i] == '$')
		return (NULL);
	i++;
	while (s[i])
	{
		if (is_var_delimiter(s, i))
			return (ft_substr(s, start, i - 1));
		i++;
	}
	if (is_var_delimiter(s, i))
		return (ft_substr(s, start, i - 1));
}

int		is_variable(t_env *env, char *s, int i)
{
	char	*name;

	if (is_variable_word(s, i))
	{
		name = var_name_extraction(s, i++);
		if (!name)
			return (0);
		if (variable_exist(env, name))
			return (free(name),1);
		free(name);
	}
	return (0);
}

int		is_valid_variable(t_env *env, char *name)
{
	if (!(is_variable(env, name, 0) && is_variable_word(name, 0))
		return (0);
	return (1);
}

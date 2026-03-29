#include "../minishell.h"

char	*ft_get_env_var_value(char *var)
{
    char    *name;
    int     start;
    int     end;
    int     i;

    i = 0;
    start = 0;
    if (!var)
        return (NULL);
    while (var[i])
    {
        if (!(is_blank(var[i + 1])) && var[i] == '=')
        {
            end = ft_strlen(var);
			start = i + 1;
            name = ft_substr(var, start, end);
            if (is_value_null(name)) 
			{
				free(value);
                return (NULL);
			}
            return (name);
        }   
        i++;
    }
    return (NULL);
}

char	*ft_get_var_name(char *var)
{
    char    *name;
    int     start;
    int     end;
    int     i;

    i = 0;
    start = 0;
    if (!var)
        return (NULL);
    while (var[i])
    {
        if (var[i] == '=')
        {   
            end = i - 1; 
            name = ft_substr(var, start, end);
            if (!name)
                return (NULL);
            return (name);
        }
        i++;
    }
    end = i;
    name = ft_substr(var, start, end);  
    return (name);
}

char	*ft_get_export_var_name(char *var)
{
	char	*name;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	if (!var)
		return (NULL);
	while (var[i])
	{
		if (is_blank(var[i]))
			return (NULL);
		else if (var[i] == '=')
		{
			end = i - 1;
			name = ft_substr(var, start, end);
			if (!name)
				return (NULL);
			return (name);
		}	
		i++;
	}
	end = i;
	name = ft_substr(var, start, end);
	return (name);
}

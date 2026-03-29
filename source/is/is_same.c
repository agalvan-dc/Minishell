#include "../minishell.h"

int		is_same_name(char *s, char *p)
{
	if (ft_strncmp(s, p, ft_strlen(s) == 0))
		return (1);
	return (0);
}

int		is_valid_identifier(char *s)
{
    int     i;

    if (!s || (!ft_isalpha(s[0]) && s[0] != '_'))
        return (0);
    i = 1;
    while (s[i] && s[i] != '=')
    {
        if (!ft_isalnum(s[i]) && s[i] != '_')
            return (0);
        i++;
    }
    return (1);
}

int     is_flag_n(char *s)
{
    if (!flags)
        return (0);
    if (flags[0] == '-' && flags[1] == 'n' && flags[2] == '\0')
        return (1);
    return (0);
}

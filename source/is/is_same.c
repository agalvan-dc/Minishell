#include "../../minishell.h"


int		is_same_name(char *s, char *p)
{
	int		cmp;

	cmp = ft_strncmp(s, p, ft_strlen(s));
	if (cmp == 0 && ft_strlen(s) == ft_strlen(p))
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

int     is_flag_n(char *flags)
{
    if (!flags)
        return (0);
    if (flags[0] == '-' && flags[1] == 'n' && flags[2] == '\0')
        return (1);
    return (0);
}

int		is_numeric(char *s)
{
    int     i;

    i = 0;
    if (s[i] == '-' || s[i] == '+')
        i++;
    while (s[i])
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return (0);
        i++;
    }
    return (1);
}

int     is_absolute_path(char *content)
{
    if (!content)
        return (0);
    if (content[0] == '/')
        return (1);
    if (content[0] == '.' && content[1] == '/')
        return (1);
    return (0);
}

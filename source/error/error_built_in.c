#include "../../minishell.h"

int		ft_check_error_pwd(t_cmd *cmd)
{
	(void)cmd;
	return (0);
}

int     ft_check_error_exit(t_cmd *cmd)
{
    int		nb_arg;
    t_arg	*arg;

    nb_arg = ft_get_number_args(cmd);
    if (nb_arg > 1)
    {
        ft_putendl_fd("minishell: exit: too many arguments", 2);
        return (1);
    }
    if (nb_arg == 1)
    {
        arg = ft_get_first_arg(cmd);
        if (!is_numeric(arg->content))
        {
            ft_putstr_fd("minishell: exit: ", 2);
            ft_putstr_fd(arg->content , 2);
            ft_putendl_fd(": numeric argument required", 2);
            return (1);
        }
    }
    return (0);
}

int		ft_check_error_env(t_cmd *cmd)
{
	(void)cmd;
	return (0);
}

int     ft_check_error_unset(t_cmd *cmd)
{
    t_arg	*arg;
    int     nb_arg;
    int     res;

    res = 0;
    nb_arg = ft_get_number_args(cmd);
    if (nb_arg == 0)
        return (0);
    arg = ft_get_first_arg(cmd);
    while (arg)
    {
        if (!is_valid_identifier(arg->content))
        {
            ft_putstr_fd("minishell: unset: ", 2);
            ft_putstr_fd(arg->content , 2);
            ft_putendl_fd("': not a valid identifier", 2);
            res += 1;
        }
        arg = arg->next;
    }
    return (res);
}

int     ft_check_error_export(t_cmd *cmd)
{
    t_arg	*arg;
    int     nb_arg;
    int     res;

    res = 0;
    nb_arg = ft_get_number_args(cmd);
    if (nb_arg == 0)
        return (0);
    arg = ft_get_first_arg(cmd);
    while (arg)
    {
        if (!(is_valid_identifier(arg->content)))
       	{
            ft_putstr_fd("minishell: export: '", 2);
            ft_putstr_fd(arg->content , 2);
            ft_putendl_fd("': not a valid identifier", 2);
            res += 1;
        }
        arg = arg->next;
    }
    return (res);
}

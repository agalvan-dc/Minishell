/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_built_in.c                                   :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/13 02:09:14 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#include "../../minishell.h"

int		ft_check_error_pwd(t_cmd *cmd)
{
	(void)cmd;
	return (0);
}

int     ft_check_error_exit(t_cmd *cmd)
{
    (void)cmd;
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

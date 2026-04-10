#include "../../minishell.h"

int     ft_check_error_cd(t_cmd *cmd)
{
    int     nb_arg;
    int     res;

    res = 0;
    nb_arg = ft_get_number_args(cmd);
    if (nb_arg > 1)
    {
        res += 1;
        ft_printf("cd: Too many arguments.\n");
    }
    return (res);
}

int		ft_check_error_builtin(t_cmd *cmd)
{
	int		res;

	res = 0;
	if (is_cd(cmd))
    	res += ft_check_error_cd(cmd);
	if (is_exit(cmd))
    	res += ft_check_error_exit(cmd);
	if (is_export(cmd))
    	res += ft_check_error_export(cmd);
	if (is_unset(cmd))
    	res += ft_check_error_unset(cmd);
	return (res);
}

int		ft_check_error_echo(t_cmd *cmd)
{
	(void)cmd;
	return (0);
}

int		ft_check_error_token_word(t_env *env, t_token *token)
{
	t_word	*word;

	word = ft_get_class(token);
	if (word)
		return (1);
	ft_putendl_fd("Error : [Unknown tokens]", 2);
	ft_putendl_fd(word->content, 2);
	ft_update_var_status_process(env, 127);
	return (1);
}

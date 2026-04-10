#include "../../minishell.h"

void	ft_processing_bin(t_env *env)
{
	t_cmd 	*cmd;
	t_token	*token;
	char	**bins;

	bins = ft_get_list_of_bins(env);
	token = ft_get_first_token_cmd(env);
	while (token)
	{
		cmd = ft_get_class(token);
		if (is_cmd_bin(cmd))
		{
			ft_setup_bin_path(cmd, bins);
			ft_setup_bin_args(cmd, bins);
		}
		token = ft_get_next_token_cmd(token);
	}
	free_array(bins);
}

void	ft_processing_cmd_args(t_env *env)
{
	ft_get_arg_var_value(env);
	ft_concatenate_cmd_args(env);
}

void    ft_processing_cmd(t_env *env)
{

    ft_processing_builtin(env);
    ft_processing_cmd_args(env);
    ft_processing_bin(env);
    if (env->verbose == 1)
    {
        printf("==== Processing Command ====\n");
        ft_print_all_cmd_info(env);
        printf("========\n");
    }
}

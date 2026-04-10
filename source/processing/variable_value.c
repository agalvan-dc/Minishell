#include "../../minishell.h"

void	ft_change_arg_var_content(t_env *env, t_arg *arg)
{
	char	*name;
	char	*value;

	name = malloc_strcpy(arg->content);
	free(arg->content);
	arg->content = NULL;
	value = ft_get_env_var_value_with_name(env, name);
	if (!value)
		arg->content = malloc_strcpy("");
	else
		arg->content = malloc_strcpy(value);
	free(name);
}

void	ft_get_arg_var_value(t_env *env)
{
	t_token		*token;
	t_arg		*arg;

	token = ft_get_first_token(env);
	while (token)
	{
		if (is_token_cmd(token) && token_have_args(token))
		{
			arg = ft_get_first_arg(ft_get_class(token));
			while (arg)
			{
				if (is_arg_var(arg))
					ft_change_arg_var_content(env, arg);
				arg = arg->next;
			}
		}
		token = token->next;
	}
}

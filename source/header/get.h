
#ifndef GET_H
#define GET_H


#include "class.h"

void	*ft_get_class(t_token *token);

char	*ft_get_env_var_value_with_name(t_env *env, char *name);
t_var	*ft_get_env_var_with_name(t_env *env, char *name);
t_var	*ft_get_first_env_var(t_env *env);
t_var	*ft_get_last_env_var(t_env *env);
int		ft_get_env_var_size(t_env *env);

t_arg	*ft_get_first_arg(t_cmd *cmd);
char	*ft_get_cmd_args(t_cmd *cmd);
int		ft_get_number_args(t_cmd *cmd);
t_arg	*ft_get_cmd_flags(t_cmd *cmd);

t_token	*ft_get_first_token_cmd(t_env *env);
t_token	*ft_get_first_token_builtin(t_env *env);
t_token	*ft_get_first_token_bin(t_env *env);
t_cmd	*ft_get_prev_cmd(t_token *token);
char	*ft_get_cmd_path(t_cmd *cmd);



char	*ft_get_rest_single_quote(char *line, int start, int end, char *quote);

#endif

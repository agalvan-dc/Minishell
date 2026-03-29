
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

char	**ft_get_env_var(t_env *env);
char	**ft_get_env_bins(t_env *env);
t_line	*ft_get_first_line(t_env *env);

t_token	*ft_get_next_token_cmd(t_token *token);
t_token	*ft_get_next_token_builtin(t_token *token);
t_token	*ft_get_next_token_bin(t_token *token);
t_token	*ft_get_next_token_file(t_token *token);
t_token	*ft_get_next_cmd(t_token *token);

char	*ft_get_home_path(t_env *env);
char	*ft_get_current_path(void);
char	*ft_get_last_path(t_env *env);

t_token	*ft_get_first_token_redirection(t_env *env);
t_token	*ft_get_next_token_redirection(t_env *env);
t_rendir	*ft_get_first_redirection(t_env *env);
int		ft_get_nbr_pipes(t_env *env);

t_token	*ft_get_first_token(t_env *env);
t_cmd	*ft_get_first_cmd(t_env *env);

char	*ft_get_content_double(char *line, int start, int *index);
char	*ft_get_rest_single_quote(char *line, int start, int end, char *quote);

char	*ft_get_env_var_value(char *var);
char	*ft_get_var_name(char *var);
char	*ft_get_export_var_name(char *var);

#endif

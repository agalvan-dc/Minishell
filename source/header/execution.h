#ifndef EXECUTION_H
#define EXECUTION_H

#include "class.h"

int			ft_test_bin_access(char **bins, char *word);
int			ft_test_absolute_bin_access(char *path);
char		**ft_get_list_of_bins(t_env *env);

void		ft_bin_execution(t_env *env, t_cmd *cmd, char **var);

void		ft_execution(t_env *env);
int			ft_execute_cmd(t_env *env, t_token *token);
int			ft_wait_all_pid(t_env *env);

char		**ft_append_bin_name_in_args(char **args, char *name);
char		*ft_extract_bin_name_in_path(char *path);
void		ft_setup_bin_path(t_cmd *cmd, char **bins);
void		ft_setup_bin_args(t_cmd *cmd, char **bins);
char		*ft_create_path_bin(char **bins, char *cmd);

int			ft_built_in_execution(t_env *env, t_cmd *cmd);

int			ft_get_last_status(int bin_status, int ret_builtin);
int			ft_convert_status_process_value(int status);
void		ft_update_var_status_process(t_env *env, int status);

int			ft_echo(t_cmd *cmd);
int			ft_cd(t_cmd *cmd, t_env *env);
int			ft_pwd(t_cmd *cmd);
int			ft_env_builtin(t_cmd *cmd, t_env *env);
int			ft_export_builtin(t_cmd *cmd, t_env *env);
int			ft_unset(t_cmd *cmd, t_env *env);
void		ft_exit_builtin(t_cmd *cmd, t_env *env);

#endif

#ifndef EXECUTION_H
#define EXECUTION_H

#include "class.h"


int		ft_built_in_execution(t_env *env, t_cmd *cmd);

int			ft_echo(t_cmd *cmd);
int			ft_cd(t_cmd *cmd, t_env *env);
int			ft_pwd(t_cmd *cmd);
int			ft_env_builtin(t_cmd *cmd, t_env *env);
int			ft_export_builtin(t_cmd *cmd, t_env *env);
int			ft_unset(t_cmd *cmd, t_env *env);
void		ft_exit_builtin(t_cmd *cmd, t_env *env);

#endif

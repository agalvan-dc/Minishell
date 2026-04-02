#ifndef FREE_H
#define FREE_H

#include "class.h"

void	ft_free_env_var(t_var *var);

void	ft_disconnect_args(t_arg *curr_arg);
void	ft_disconnect_line(t_line *curr_line);
void	ft_disconnect_env_var(t_env *env, t_var *var);
void	ft_disconnect_env_var_first(t_env *env, t_var *var, t_var *var_next);
void	ft_disconnect_token(t_token *token);

void	ft_remove_arg(t_arg *arg);
void	ft_remove_all_arg(t_cmd *cmd);
void	ft_remove_arg_index(t_cmd *cmd, t_arg *arg);
void	ft_remove_arg_in_cmd(t_cmd *cmd, t_arg *arg);
void	ft_remove_env_vars(t_env *env);

void	ft_remove_token(t_token *token);
void	ft_remove_all_token(t_env *env);

void	ft_remove_token_cmd(t_cmd *cmd);
void	ft_remove_token_redir(t_redir *redir);
void	ft_remove_token_file(t_file *file);
void	ft_remove_token_word(t_word *word);
void	ft_remove_and_disconnect_env_var(t_env *env, t_var *var);

void	ft_remove_blank_arg(t_cmd *cmd);

#endif

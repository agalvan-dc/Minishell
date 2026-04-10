#ifndef VERBOSE_H
#define VERBOSE_H

#include "class.h"

void	ft_print_heredoc_info(t_redir *redir, t_cmd *prev_cmd);
void	ft_print_input_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file);
void	ft_print_output_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file);
void    ft_print_append_chevron(t_redir *redir, t_cmd *prev_cmd, t_file *next_file);

void	ft_print_cmd(t_cmd *cmd, int index);
void	ft_print_args(t_cmd *cmd);
void	ft_print_args_array(char **args);
void	ft_print_redir(t_token *token, t_redir *redir);

void	ft_print_cmd_info(t_cmd *cmd);
void	ft_print_all_cmd_info(t_env *env);

void	ft_print_line(t_line *line);
void	ft_print_all_line(t_env *env);

void	ft_print_env_var(t_var *var);
void	ft_print_all_env_export_var(t_env *env);
void	ft_print_all_env_var(t_env *env);

void	ft_print_redirect(t_token *token, t_cmd *prev_cmd, t_cmd *next_cmd, t_file *next_file);
void	ft_print_all_redir_info(t_env *env);
void	ft_print_pipe_info(t_redir *redir, t_cmd *prev_cmd, t_cmd *next_cmd);

void	ft_print_chained_list(t_env *env);
void	ft_print_token(t_token *token);

void	ft_print_all_env_export_var_fd(t_env *env, int fd);
void	ft_print_all_env_var_fd(t_env *env, int fd);
void	ft_print_env_var_fd(t_var *var, int fd);

#endif

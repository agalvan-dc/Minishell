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

#endif

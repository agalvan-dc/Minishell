/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.h                                       :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef PROCESSING_H
#define PROCESSING_H

#include "class.h"

void	ft_processing_builtin(t_env *env);
void	ft_choose_processing_builtin(t_env *env, t_cmd *cmd);
void	ft_processing_exit(t_env *env, t_cmd *cmd);
void	ft_processing_echo(t_cmd *cmd);
void	ft_processing_cd(t_env *env, t_cmd *cmd);
void	ft_processing_cmd(t_env *env);
void	ft_processing_cmd_args(t_env *env);
void	ft_processing_bin(t_env *env);
void	ft_get_arg_var_value(t_env *env);
void	ft_change_arg_var_content(t_env *env, t_arg *arg);
void	ft_processing_redir(t_env *env);
void	ft_change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out);
void	ft_redirect_cmd(t_cmd *cmd);

#endif

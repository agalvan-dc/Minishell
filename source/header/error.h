/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef ERROR_H
#define ERROR_H

#include "class.h"

void	ft_reset_counter_error(t_env *env);
int		ft_doesnt_have_error_parsing(t_env *env);
int		ft_doesnt_have_error_processing(t_env *env);
void	ft_check_error_parsing(t_env *env);
int		ft_check_error_token_cmd(t_token *token);
int		ft_check_error_token_redir(t_token *token);
int		ft_check_error_token_word(t_env *env, t_token *token);
int		ft_check_error_token_heredoc(t_redir *redir);
int		ft_check_error_token_pipe(t_token *token, t_redir *redir);
int		ft_check_error_token_basic_redir(t_token *token, t_redir *redir);
int		ft_check_error_builtin(t_cmd *cmd);
int		ft_check_error_echo(t_cmd *cmd);
int		ft_check_error_pwd(t_cmd *cmd);
int		ft_check_error_exit(t_cmd *cmd);
int		ft_check_error_cd(t_cmd *cmd);
int		ft_check_error_env(t_cmd *cmd);
int		ft_check_error_unset(t_cmd *cmd);
int		ft_check_error_export(t_cmd *cmd);

#endif

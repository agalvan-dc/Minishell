/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
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
void	ft_remove_all(t_env *env);
void	ft_remove_line(t_line *line);
void	ft_remove_all_line(t_env *env);
void	ft_remove_env_var(t_var *var);
void	ft_remove_var_list(t_env *env);
void	ft_remove_blank_arg(t_cmd *cmd);

#endif

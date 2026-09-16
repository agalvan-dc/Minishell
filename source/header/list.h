/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIST_H
#define LIST_H

#include "class.h"

/* concatenate */
int		ft_size_of_cmd_list(t_cmd *cmd);
int		ft_size_of_var_list(t_env *env);
char	**ft_cmd_list_to_array(t_cmd *cmd);
char	**ft_var_list_to_array(t_env *env);
char	*ft_cmd_list_to_str(t_cmd *cmd);
void	ft_concatenate_cmd_args(t_env *env);
void	ft_remove_blank_arg(t_cmd *cmd);

/* add list */
void	ft_add_line_list(t_env *env, t_line *line);
void	ft_add_var_list(t_env *env, t_var *var);
void	ft_add_token_list(t_env *env, t_token *token);
void	ft_add_arg_list(t_cmd *cmd, t_arg *arg);
void	ft_add_line_to_env(t_env *env, char *content);

#endif

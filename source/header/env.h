/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef ENV_H
#define ENV_H

#include "class.h"

void	ft_add_signal_env_var(t_env *env);
void	ft_add_line_to_env(t_env *env, char *content);
void	ft_update_var_status_process(t_env *env, int status);
void	ft_sigint_handler(int sig);
void	ft_change_or_create_var(t_env *env, char *name, char *value, int fd);
int		ft_assign_env_var_id(char *value);
void	ft_create_chained_var(t_env *env, char **env_variable);
void	ft_add_new_env_var(t_env *env, t_var *new_env);
char	**ft_add_env_var(char **var, char *variable);
void	ft_change_env_var_value(t_var *var, char *new_value);
void	ft_change_env_var_value_with_name(t_env *env, char *name, char *vallue);
char	*ft_get_line(void);
int		ft_env_have_multi_line(t_env *env);
void	ft_execute_line(t_env *env, char *line);
void	ft_execute_multi_line(t_env *env, t_line *line);
void	ft_prompt(t_env *env);
void	ft_create_history(char *line);
int		ft_line_is_empty(char *line);
void	ft_write_line(char *line, int fd);
void	ft_use_signal(void);
void	ft_use_signal_exec(void);

#endif

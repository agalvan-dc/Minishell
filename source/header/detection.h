/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detection.h                                        :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef DETECTION_H
#define DETECTION_H

#include "class.h"

int		ft_arg_redirect_extraction(t_token *token, t_env *env, char *line, int i);
int		ft_word_arg_extraction(t_env *env, t_cmd *cmd, char *line, int index);
int		ft_string_extraction(t_env *env, t_cmd *cmd, char *line, int index);
int		ft_limiter_extraction(t_redir *redir, char *line, int i);
int		ft_redir_classification(t_env *env, char *line, int i);
int		ft_word_classification(t_env *env, char *line, int i);
int		ft_arg_classification(t_env *env, t_cmd *cmd, char *line, int i);
t_token	*ft_cmd_classification(t_env *env, char *content);
int		ft_type_of_redirect(char *content);
int		ft_type_of_boolean(char *content);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef PARSER_H
#define PARSER_H

#include "class.h"

int		ft_word_detection(t_env *env, char *line, int index);
int		ft_word_arg_detection(t_env *env, char *line, int index);
int		ft_file_detection(char *line, int index);
int		ft_blank_detection(char *line, int index);
int		ft_blank_escape(char *line, int index);
int		ft_single_quote_detection(char *line, int index);
int		ft_double_quote_detection(char *line, int index);
int		ft_redirection_detection(char *line, int index);
int		ft_limiter_detection(char *line, int index);
int		ft_variable_detection(char *line, int index);
int		ft_return_last_backslash_index(char *line);
void	ft_parsing(t_env *env, char *line);

#endif

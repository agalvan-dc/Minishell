/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
#ifndef REDIRECTION_H
#define REDIRECTION_H

#include "class.h"

int		ft_compare_line(char *line, char *limiter, int fd_tmp);
char	*ft_heredoc_prompt(char *limiter);
char	*ft_heredoc_not_finish(char *limiter);
char	*ft_read_and_extract_content_file(char *path);
void	ft_open_next_file_with_flags(t_token *token, t_file *file);
void	ft_manage_fd_for_redir(t_token *token);
void	ft_manage_fd_basic_redir(t_token *token);
void	ft_manage_fd_pipe(t_token *token);
void	ft_manage_fd_heredoc(t_token *token);
void	ft_close_all_fd(t_env *env);
void	ft_close_fd_cmd(t_cmd *cmd);
void	ft_remove_tmp_file(t_token *token_heredoc);

#endif

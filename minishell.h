#ifndef MINISHELL_H
#define MINISHELL_H

#define BUFF_SIZE 4096

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <curses.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "source/libft/libft.h"
#include "source/header/token.h"
#include "source/header/class.h"
#include "source/header/free.h"
#include "source/header/get.h"
#include "source/header/execution.h"
#include "source/header/is.h"
#include "source/header/verbose.h"

extern t_env	*g_env;

void	ft_ask_verbose(t_env *env);
t_env	*ft_init_env(char **env_var);
t_var	*ft_init_env_var(char *name, char *value, int id);
t_line	*ft_init_line(char *content);

void	ft_add_signal_env_var(t_env *env);
void	ft_add_line_to_env(t_env *env, char *content);
void	ft_update_var_status_process(t_env *env, int status);

void	ft_change_or_create_var(t_env *env, char *name, char *value, int fd);
int		ft_assign_env_var_id(char *value);
void	ft_create_chained_var(t_env *env, char **env_variable);
void	ft_add_new_env_var(t_env *env, t_var *new);
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

int		ft_return_last_backslash_index(char *line);

void	ft_use_signal(void);
void	ft_call_prompt(int key);
void	ft_pass(int key);
void	ft_exit_prompt(int key);
void	ft_stop_prompt(int key);


void	ft_write_line(char *line, int fd);

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

int		ft_single_tokenizer(t_cmd *cmd, char *line, int index);
int		ft_double_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
void	ft_double_tokenization(t_env *env, t_cmd *cmd, char *content);
int		ft_blank_arg_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int		ft_variable_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int		ft_arg_extraction(t_env *env, t_cmd *cmd, char *line, int index);

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

void	ft_parsing(t_env *env, char *line);
void	ft_processing_redir(t_env *env);
void	ft_change_fd_cmd(t_cmd *cmd, int fd_in, int fd_out);
void	ft_redirect_cmd(t_cmd *cmd);

void    ft_add_line_list(t_env *env, t_line *line);
void	ft_add_var_list(t_env *env, t_var *var);
void	ft_add_token_list(t_env *env, t_token *token);
void	ft_add_arg_list(t_cmd *cmd, t_arg *arg);
void    ft_add_line_to_env(t_env *env, char *content);

void	ft_processing_builtin(t_env *env);
void	ft_choose_processing_builtin(t_env *env, t_cmd *cmd);
void	ft_processing_exit(t_cmd *cmd);
void	ft_processing_echo(t_cmd *cmd);
void	ft_processing_cd(t_env *env, t_cmd *cmd);

void	ft_processing_cmd(t_env *env);
void	ft_processing_cmd_args(t_env *env);
void	ft_processing_bin(t_env *env);

void	ft_get_arg_var_value(t_env *env);
void	ft_change_arg_var_content(t_env *env, t_arg *arg);

void	ft_concatenate_cmd_args(t_env *env);
void	ft_change_arg_var_content(t_env *env, t_arg *arg);

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

int		ft_wait_all_pid(t_env *env);
int		ft_get_last_status(int bin_status, int ret_builtin);

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

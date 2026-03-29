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

#include "libft/libft.h"
#include "header/token.h"
#include "header/class.h"
#include "header/free.h"
#include "header/get.h"
#include "header/execution.h"
#include "header/is.h"
#include "header/verbose.h"

extern t_env	*g_env;

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
int		ft_redirectionn_detection(char *line, int index);
int		ft_limiter_detection(char *line, int index);




void	ft_parsing(t_env *env, char *line);

void    ft_add_line_list(t_env *env, t_line *line);
void	ft_add_var_list(t_env *env, t_var *var);
void	ft_add_token_list(t_env *env, t_token *token);
void	ft_add_arg_list(t_cmd *cmd, t_arg *arg);
void    ft_add_line_to_env(t_env *env, char *content);



void	ft_concatenate_cmd_args(t_env *env);
void	ft_change_arg_var_content(t_env *env, t_arg *arg);



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

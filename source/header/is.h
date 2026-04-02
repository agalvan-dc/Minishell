
#ifndef IS_H
#define IS_H

#include "class.h"

int		is_not_null(char s, char c);
int		is_null(char *s);
int		is_value_null(char *s);
int		is_backslash(char c);
int		is_word(t_env *env, char *s, int i);

int		is_blank(char c);
int		is_blank_arg(t_env, *env, char *s, int i);
int		is_blank_before_redir(char *s, int i);
int		is_blank_before_finish(char *s, int i);

int		is_separator(char *s, int i);
int		is_delimiter(t_env *env, char *s, int i);
int		is_var_delimiter(char *s, int i);
int		is_arg_sep(t_env *env, char *s, int i);
int		is_word_arg_sep(t_env *env, char *s, int i);

int		is_redirection(char *s, int i);
int		is_pipe(char *s, int i);
int		is_file_redir(char *s, int i);

int		have_token(t_env *env);
int		have_token_redir(t_env *env);
int		token_have_args(t_token *token);

int		cmd_have_args(t_cmd *cmd);
int		cmd_have_argument(t_cmd *cmd);
int		cmd_have_arg_flags(t_cmd *cmd);
int		cmd_have_flags(t_cmd *cmd);
int		cmd_have_args_array(t_cmd *cmd);

int		is_token_word(t_token *token);
int		is_token_file(t_token *token);
int		is_token_basic_redir(t_token *token);
int		is_token_redir_heredoc(t_redir *redir);

int		is_token_output_chevron(t_token *token);
int		is_token_input_chevron(t_token *token);
int		is_token_append_chevron(t_token *token);
int		is_token_redir(t_token *token);
int		is_token_pipe(t_token *token);
int		is_token_heredoc(t_token *token);

int		is_token_cmd(t_token *token);
int		is_token_bin(t_token *token);
int		is_token_builtin(t_token *token);
int		is_cmd_bin(t_cmd *cmd);
int		is_cmd_builtin(t_cmd *cmd);

int		is_output_chevron(char *s, int i);
int		is_input_chevon(char *s, int i);
int		is_append_chevron(char *s, int i);
int		is_heredoc(char *s, int i);

int		is_arg_var(t_arg *arg);
int		is_arg_flags(t_arg *arg);
int		is_arg_blank(t_arg *arg);

int		is_echo(t_cmd *cmd);
int		is_pwd(t_cmd *cmd);
int		is_export(t_cmd *cmd);
int		is_cd(t_cmd *cmd);
int		is_env(t_cmd *cmd);

int		is_exit(t_cmd *cmd);
int		is_unset(t_cmd *cmd);
int		is_bin(t_env *env, char *word);
int		is_cmd(t_env *env, char *word);
int		is_builitin(char *content);

int		is_arg(char *s, int i);
int		is_flag(char *s, int i);

int		is_standard_fd(int fd);
int		isnot_standard_fd(int fd);
int		cmd_have_standard_fd(t_cmd *cmd);

int		is_file(char *s, int i);
int		is_after_redirect(char *s, int i);
int		is_after_heredoc(char *s, int i);
int		is_delimiter(char *s, int i);

int		is_finish(char c);
int		index_is_overflow(char *s, int i);

int		line_is_finish(char *s, int i);
int		line_is_empty(char *s);
int		is_dollar_word(t_env *env, char *s, int i);

int		is_double_quote(char c);
int		is_single_quote(char c);
int		is_quote(char c);

int		is_variable(t_env *env, char *s, int i);
int		is_valid_variable(t_env *env, char *name);
int		is_variable_word(char *s, int i);
int		is_variable_exist(t_env *env, char  *name);
char	*var_name_extraction(char *s, int i);

int		is_same_name(char *first, char *second);
int		is_valid_identifier(char *s);
int		is_flag_n(char *s);

#endif

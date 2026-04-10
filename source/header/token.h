#ifndef TOKEN_H
#define TOKEN_H

#include "class.h"

#define TOKEN_NULL 0
#define TOKEN_BLANK 1
#define TOKEN_WORD 2
#define TOKEN_SINGLE_QUOTE 3
#define TOKEN_DOUBLE_QUOTE 4
#define TOKEN_PARENTHESIS 5
#define TOKEN_CMD 6
#define TOKEN_BUILTIN 7
#define TOKEN_BIN 8
#define TOKEN_FLAGS 9
#define TOKEN_ARG 10
#define TOKEN_VARIABLE 11
#define TOKEN_FILE 12
#define TOKEN_AND 13
#define TOKEN_OR 14
#define TOKEN_WILDCARD 15
#define TOKEN_REDIR 16
#define TOKEN_PIPE 17
#define TOKEN_INPUT_CHEVRON 18
#define TOKEN_OUTPUT_CHEVRON 19
#define TOKEN_APPEND_CHEVRON 20
#define TOKEN_HEREDOC 21
#define TOKEN_BOOLEAN 22
#define TOKEN_LIMITER 23
#define TOKEN_STRING 24
#define TOKEN_NOT_FINISH 25

t_file	*ft_init_file(char *name, int fd);
t_redir	*ft_init_redir(int type, char *content);
t_redir	*ft_init_heredoc(int type, char *content, char *delimiter);
t_token	*ft_init_token(void);
t_arg	*ft_init_arg(char *content, int id);
t_blank	*ft_init_blank(char *content, int id);
t_word	*ft_init_word(char *content, int id);
t_cmd	*ft_init_cmd(char *content, int id);

void	ft_tokenization(t_env *env, char *line);
int		ft_single_tokenization(t_cmd *cmd, char *line, int start, int index);
t_token	*ft_cmd_tokenization(char *word, int fd);
t_token	*ft_word_tokenizer(char *content, int id);
int		ft_next_file_tokenizer(t_env *env, char *line, int index);
void	ft_word_arg_tokenizer(t_env *env, t_cmd *cmd, char *content);
t_token	*ft_file_tokenizer(char *name, int id);
int		ft_blank_arg_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);


int		ft_cmd_tokenizer(t_env *env, char *line, char *content, int index);
t_arg	*ft_arg_tokenizer(char *line, int start, int end, int fd);
int		ft_flags_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int		ft_var_tokenizer(t_env *env, t_cmd *cmd, char *line, int index);
int		ft_vars_tokenization(t_env *env, t_cmd *cmd, char *line, int index);

t_token	*ft_create_token_word(char *content, int id);
t_token	*ft_create_token_redir(char *content, int index, int new_i);
t_token	*ft_create_token_cmd(char *content, int id);
t_token	*ft_create_token_file(char *name, int fd, int id);
t_arg	*ft_create_arg(char *content, int id);

void	ft_connect_new_var(t_var *curr_var, t_var *prev_var, t_var *next_var);
void	ft_connect_var(t_var *curr_var, t_var *next_var);
void	ft_connect_token(t_token *curr_token, t_token *next_token);
void	ft_connect_arg(t_arg *curr_arg, t_arg *next_arg);
void	ft_connect_line(t_line *curr_line, t_line *next_line);

char	*ft_get_content_double(char *line, int start, int *index);

int		ft_size_of_cmd_list(t_cmd *cmd);
int		ft_size_of_var_list(t_env  *env);

char	**ft_cmd_list_to_array(t_cmd *cmd);
char	**ft_var_list_to_array(t_env *env);
char	*ft_cmd_list_to_str(t_cmd *cmd);

#endif

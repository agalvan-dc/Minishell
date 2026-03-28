#ifndef TOKEN_H
#define TOKEN_H

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




char	*ft_get_content_double(char *line, int start, int *index);

#endif

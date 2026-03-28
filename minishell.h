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

#endif

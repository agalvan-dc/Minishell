/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                      +:+/:+          :+:   */
/*   By: agalvan- <agalvan-@student.42madrid.c          +#+  :+:       +#:    */
/*                                                      +#+#+#+#+#+   +#+     */
/*   Created: 2026/09/13 00:35:08 by agalvan-           #+#    #+#            */
/*   Updated: 2026/09/17 01:33:00 by agalvan-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */
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
#include <readline/readline.h>
#include <readline/history.h>

#include "source/libft/libft.h"

#include "source/header/class.h"
#include "source/header/token.h"
#include "source/header/list.h"
#include "source/header/detection.h"
#include "source/header/is.h"
#include "source/header/get.h"
#include "source/header/parser.h"
#include "source/header/processing.h"
#include "source/header/env.h"
#include "source/header/redirection.h"
#include "source/header/execution.h"
#include "source/header/error.h"
#include "source/header/free.h"
#include "source/header/verbose.h"

extern t_env	*g_env;

#endif

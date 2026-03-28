
NAME = minishell

SRC = $(wildcard *.c)

SRC += $(wildcard source/built_in/*.c)
SRC += $(wildcard source/concatenate/*.c)
SRC += $(wildcard source/detection/*.c)
SRC += $(wildcard source/env/*.c)
SRC += $(wildcard source/error/*.c)
SRC += $(wildcard source/execution/*.c)
SRC += $(wildcard source/exit_free/*.c)
SRC += $(wildcard source/get/*.c)
SRC += $(wildcard source/init/*.c)
SRC += $(wildcard source/is/*.c)
SRC += $(wildcard source/parsing/*.c)
SRC += $(wildcard source/processing/*.c)
SRC += $(wildcard source/redirection/*.c)
SRC += $(wildcard source/tokenization/*.c)
SRC += $(wildcard source/verbose/*.c)
SRC += $(wildcard source//*.c)

HEADER = header/class.h \
		header/execution.h \
		header/free.h \
		header/get.h \
		header/is.h \
		header/token.h \
		header/verbose.h \

TEMPLATE  = source/header/header.txt

EXE = @./$(NAME)
LIBFT = source/libft/libft.a

SANITIZE = -fsanitize=address
LEAKS = -fsanitize=leak
DEBUGGER = lldb

RM_FILE = /bin/rm -rf

OBJS = $(SRC:.c=.o)
CC ?= gcc
FLAGS = -g3
FLAGS += -Wall -Wextra -Werror
FLAGS += $(SANITIZE)
READLINE = -lreadline
MAKE = make -s

UNAME = $(shell uname -s)

ifeq ($(UNAME), linux)
	NPROC := $(shell nproc)

else
	NPROC := $(shell sysctl -n hw.ncpu)
	FLAGS += -I$(HOME)/.brew/opt/readline/include
	READLINE += -L$(HOME)/.brew/opt/readline/lib

endif

all : $(NAME)

clean :
		@echo "==== Remove all Libft .o ===="
		@$(MAKE) clean -C source/libft
		@echo "==== Remove all minishell .o ===="
		@$(RM_FILE) $(OBJS)

fclean : clean
			@$(MAKE) fclean -C source/libft
			@$(RM_FILE) $(NAME)

debug :		$(OBJS)
			@echo "==== Mode debug activate ===="
			@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
			$(DEBUGGER) $(NAME)	
			@cat "$(TEMPLATE)"

sanitize :	$(OBJS)
			@echo "==== Mode sanitize activate ===="
			@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
			@cat "$(TEMPLATE)"

leak :		$(OBJS)
			@echo "==== Mode leak activate ===="
			@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
			@cat "$(TEMPLATE)"

re : fclean all
.PHONY : all clean fclean debug sanitize leak re

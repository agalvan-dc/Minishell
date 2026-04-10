
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
SRC += $(wildcard source/parser/*.c)
SRC += $(wildcard source/parsing/*.c)
SRC += $(wildcard source/processing/*.c)
SRC += $(wildcard source/redirection/*.c)
SRC += $(wildcard source/tokenization/*.c)
SRC += $(wildcard source/verbose/*.c)

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
    READLINE_PATH = $(shell brew --prefix readline)
    FLAGS += -I$(READLINE_PATH)/include
    READLINE += -L$(READLINE_PATH)/lib
endif

# === Convert all .c to .o with flags and header === # 
%.o : %.c
			@$(CC) $(FLAGS) -c $< -o $@

$(NAME) : 	    $(OBJS)
				@echo "==== Create all .o ===="
				@echo "==== Compiling all .c ===="
				@echo "==== Compiling libft ===="
				@$(MAKE) -C source/libft
				@echo "==== Compiling Minishell ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"		

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

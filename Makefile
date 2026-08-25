NAME        = minishell

SRC_DIR     = source
INC_DIR     = source/header
LIBFT_DIR   = source/libft
LIBFT       = $(LIBFT_DIR)/libft.a


SRC         = main.c \
              $(wildcard $(SRC_DIR)/built_in/*.c) \
              $(wildcard $(SRC_DIR)/concatenate/*.c) \
              $(wildcard $(SRC_DIR)/detection/*.c) \
              $(wildcard $(SRC_DIR)/env/*.c) \
              $(wildcard $(SRC_DIR)/error/*.c) \
              $(wildcard $(SRC_DIR)/execution/*.c) \
              $(wildcard $(SRC_DIR)/exit_free/*.c) \
              $(wildcard $(SRC_DIR)/get/*.c) \
              $(wildcard $(SRC_DIR)/init/*.c) \
              $(wildcard $(SRC_DIR)/is/*.c) \
              $(wildcard $(SRC_DIR)/parser/*.c) \
              $(wildcard $(SRC_DIR)/processing/*.c) \
              $(wildcard $(SRC_DIR)/redirection/*.c) \
              $(wildcard $(SRC_DIR)/tokenization/*.c) \
              $(wildcard $(SRC_DIR)/verbose/*.c)

OBJS        = $(SRC:.c=.o)

HEADERS     = $(INC_DIR)/class.h \
              $(INC_DIR)/execution.h \
              $(INC_DIR)/free.h \
              $(INC_DIR)/get.h \
              $(INC_DIR)/is.h \
              $(INC_DIR)/token.h \
              $(INC_DIR)/verbose.h

TEMPLATE    = source/header/header.txt

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(INC_DIR) -I$(LIBFT_DIR)
READLINE_LNK = -lreadline

# OS Compatibility for Readline
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    NPROC := $(shell nproc 2>/dev/null || echo 1)
    MAKEFLAGS += -j$(NPROC)
else ifeq ($(UNAME_S), Darwin)
    READLINE_PATH = $(shell brew --prefix readline 2>/dev/null)
    ifneq ($(READLINE_PATH),)
        CFLAGS        += -I$(READLINE_PATH)/include
        READLINE_LNK  += -L$(READLINE_PATH)/lib
    endif
endif

RM          = rm -rf

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@echo "==== Compiling Minishell ===="
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_LNK) -o $(NAME)
	@if [ -f "$(TEMPLATE)" ]; then cat "$(TEMPLATE)"; fi

clean:
	@echo "==== Removing Object Files ===="
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@echo "==== Removing Executables ===="
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

 
debug: CFLAGS += -g3
debug: re

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: re

leak: CFLAGS += -fsanitize=leak -g3
leak: re

.PHONY: all clean fclean re debug sanitize leak

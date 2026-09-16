# =========================================================================== #
#                                MINISHELL                                    #
# =========================================================================== #

NAME        = minishell

SRC_DIR     = source
LIBFT_DIR   = source/libft
LIBFT       = $(LIBFT_DIR)/libft.a
BANNER      = source/header/header.txt

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
HEADERS     = minishell.h $(wildcard $(SRC_DIR)/header/*.h)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(LIBFT_DIR)
READLINE_LNK = -lreadline

RM          = rm -rf

# --------------------------------------------------------------------------- #
#                                   COLORS                                    #
# --------------------------------------------------------------------------- #
ESC         = \033
RESET       = $(ESC)[0m
BOLD        = $(ESC)[1m
RED         = $(ESC)[1;31m
GREEN       = $(ESC)[1;32m
YELLOW      = $(ESC)[1;33m
BLUE        = $(ESC)[1;34m
CYAN        = $(ESC)[1;36m

# OS Compatibility for Readline
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    NPROC := $(shell nproc 2>/dev/null || echo 1)
else ifeq ($(UNAME_S), Darwin)
    READLINE_PATH = $(shell brew --prefix readline 2>/dev/null)
    ifneq ($(READLINE_PATH),)
        CFLAGS        += -I$(READLINE_PATH)/include
        READLINE_LNK  += -L$(READLINE_PATH)/lib
    endif
endif

# --------------------------------------------------------------------------- #
#                                    RULES                                    #
# --------------------------------------------------------------------------- #
all: check $(NAME)

# Prints the banner and checks the toolchain / dependencies before building.
# Fails with a red message if the compiler or readline is missing.
check:
	@if [ -f $(BANNER) ]; then cat $(BANNER); fi
	@command -v $(CC) >/dev/null 2>&1 || \
		{ printf "$(RED)✘ Missing dependency: compiler '$(CC)' not found$(RESET)\n"; exit 1; }
	@echo '#include <readline/readline.h>' \
		| $(CC) $(CFLAGS) -E - >/dev/null 2>&1 || \
		{ printf "$(RED)✘ Missing dependency: readline headers (install libreadline-dev)$(RESET)\n"; exit 1; }
	@printf "$(BLUE)➜ Dependencies$(RESET)  compiler $(GREEN)ok$(RESET)  readline $(GREEN)ok$(RESET)\n"

%.o: %.c $(HEADERS)
	@printf "$(CYAN)  CC$(RESET)      $<\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@printf "$(CYAN)  MAKE$(RESET)    $(LIBFT_DIR)\n"
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	@printf "$(CYAN)  LINK$(RESET)    $(NAME)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(READLINE_LNK) -o $(NAME) \
		&& printf "$(GREEN)✔ $(BOLD)$(NAME)$(RESET)$(GREEN) compiled successfully!$(RESET)\n" \
		|| { printf "$(RED)✘ Compilation failed: could not link $(NAME)$(RESET)\n"; exit 1; }

clean:
	@printf "$(YELLOW)➜ Removing object files$(RESET)\n"
	@make clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@printf "$(YELLOW)➜ Removing executables$(RESET)\n"
	@make fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: re

leak: CFLAGS += -fsanitize=leak -g3
leak: re

.PHONY: all check clean fclean re debug sanitize leak

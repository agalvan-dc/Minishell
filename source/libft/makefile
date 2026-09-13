NAME = libft.a

SRCS = check/ft_isdigit.c \
	   check/ft_isalpha.c \
	   check/ft_isalnum.c \
	   check/ft_isascii.c \
	   check/ft_isprint.c \
	   check/ft_strlen.c \
	   check/ft_strlcat.c \
	   check/ft_strchr.c \
	   check/ft_strrchr.c \
	   check/ft_strncmp.c \
	   check/ft_strnstr.c \
	   check/ft_strtrim.c \
	   check/ft_atol.c \
	   check/same_str.c \
	   array/join_array.c \
	   array/array.c \
	   conversion/ft_toupper.c \
	   conversion/ft_tolower.c \
	   conversion/ft_atoi.c \
	   conversion/ft_strdup.c \
	   conversion/ft_strjoin.c \
	   conversion/ft_substr.c \
	   conversion/ft_itoa.c \
	   conversion/ft_strmapi.c \
	   conversion/ft_striteri.c \
	   conversion/ft_split.c \
	   conversion/ft_strlcpy.c \
	   memory/ft_memset.c \
	   memory/ft_bzero.c \
	   memory/ft_memcpy.c \
	   memory/ft_memmove.c \
	   memory/ft_memchr.c \
	   memory/ft_memcmp.c \
	   memory/ft_calloc.c \
	   verbose/ft_putchar_fd.c \
	   verbose/ft_putstr_fd.c \
	   verbose/ft_putnbr_fd.c \
	   verbose/ft_putendl_fd.c \
	   verbose/print_array.c \
	   get_next_line/get_next_line.c \
	   printf/ft_check_format.c \
	   printf/ft_hexa.c \
	   printf/ft_printf.c \
	   printf/utils.c \
	   printf/ft_printf_fd.c \
	   free/free.c \
	   free/copy.c \
	   free/copy_array.c \

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -fPIE -I.

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c
	@$(CC) -c $(FLAGS) -o $@ $^

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
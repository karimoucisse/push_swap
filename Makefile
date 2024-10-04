NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/
BONUS = bonus/
GNL = gnl/
LIBFT = libft/
GNL_FILES = $(GNL)get_next_line_utils.c  $(GNL)get_next_line.c
LIBFT_FILES = $(LIBFT)ft_substr.c $(LIBFT)ft_strjoin.c $(LIBFT)ft_strtrim.c $(LIBFT)ft_split.c $(LIBFT)ft_itoa.c\
	$(LIBFT)ft_putendl_fd.c $(LIBFT)ft_putchar_fd.c $(LIBFT)ft_putstr_fd.c $(LIBFT)ft_putnbr_fd.c\
	$(LIBFT)ft_strmapi.c $(LIBFT)ft_striteri.c $(LIBFT)ft_isalnum.c $(LIBFT)ft_isalpha.c\
	$(LIBFT)ft_isascii.c $(LIBFT)ft_isdigit.c $(LIBFT)ft_isprint.c $(LIBFT)ft_strlen.c  $(LIBFT)ft_tolower.c\
	$(LIBFT)ft_toupper.c $(LIBFT)ft_strchr.c $(LIBFT)ft_strrchr.c $(LIBFT)ft_strncmp.c $(LIBFT)ft_strnstr.c\
	$(LIBFT)ft_atoi.c $(LIBFT)ft_strlcpy.c $(LIBFT)ft_strlcat.c $(LIBFT)ft_strdup.c $(LIBFT)ft_bzero.c\
	$(LIBFT)ft_memset.c $(LIBFT)ft_memcpy.c $(LIBFT)ft_memchr.c $(LIBFT)ft_memcmp.c\
	$(LIBFT)ft_memmove.c $(LIBFT)ft_calloc.c
BONUS_C_FILES = $(BONUS)args_checker_bonus.c $(BONUS)ft_sort_bonus.c\
	$(BONUS)handle_error_bonus.c $(BONUS)handle_struct_bonus.c\
	$(BONUS)push_swap_bonus.c $(BONUS)swap_cmd1_bonus.c\
	$(BONUS)swap_cmd2_bonus.c $(BONUS)utils_bonus.c $(LIBFT_FILES) $(GNL_FILES)
C_FILES = $(SRC)args_checker.c $(SRC)ft_sort1.c $(SRC)ft_sort2.c\
	$(SRC)handle_error.c $(SRC)handle_struct.c $(SRC)push_swap.c\
	$(SRC)swap_cmd1.c $(SRC)swap_cmd2.c $(SRC)utils1.c $(SRC)utils2.c $(LIBFT_FILES)
O_FILES = $(C_FILES:.c=.o)
BONUS_O_FILES = $(BONUS_C_FILES:.c=.o)
RM = rm -f

all: $(NAME)
bonus: $(BONUS_NAME)
$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -o $(NAME)
$(BONUS_NAME): $(BONUS_O_FILES)
	$(CC) $(CFLAGS) $(BONUS_O_FILES) -o $(BONUS_NAME)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	$(RM) $(O_FILES) $(BONUS_O_FILES)
fclean : clean
	$(RM) $(NAME) $(BONUS_NAME)
re: fclean all
.PHONY: all clean fclean re


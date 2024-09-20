NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
C_FILES = args_checker.c ft_sort.c handle_error.c handle_struct.c\
	push_swap.c swap_cmd.c utils.c
O_FILES = $(C_FILES:.c=.o)
RM = rm -f

all: $(NAME)
$(NAME): $(O_FILES)
	$(CC) $(CFLAGS) $(O_FILES) -L. -lft -o $(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	$(RM) $(O_FILES)
fclean : clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re


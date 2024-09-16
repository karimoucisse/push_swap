NAME = push_swap
CC = cc
C_FILES = main.c
O_FILES = $(C_FILES:.c=.o)
RM = rm -f
FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) : $(O_FILES)
	ar rcs $@ $^
run :
	$(CC) $(O_FILES) -L. -lft
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
clean :
	$(RM) $(O_FILES)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re


NAME = checker
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -rf
AR = ar -rc

SRC_BONUS = checker.c get_next_line_utils.c get_next_line.c instruction.c instruction2.c \
			instruction3.c parsing.c parsing2.c split.c utils.c utils2.c utils3.c
OBJ_BONUS := $(SRC_BONUS:%.c=%.o)


all : $(NAME)

$(NAME) : $(OBJ_BONUS)
		$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME) 

%.o : %.c checker.h
		$(CC) $(CFLAGS) -c $< -o $@

bonus : $(OBJ_BONUS) checker.h
		$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)

clean: 
	$(RM) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
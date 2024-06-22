# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 05:13:54 by aragragu          #+#    #+#              #
#    Updated: 2024/06/11 18:18:37 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf

SRC = main.c parsing.c parsing2.c instruction.c instruction2.c instruction3.c \
		utils.c utils2.c utils3.c sorting.c sorting2.c sorting3.c
OBJ := $(SRC:%.c=%.o)
SRC_BONUS = bonus/checker.c bonus/get_next_line_utils.c bonus/get_next_line.c bonus/instruction.c bonus/instruction2.c \
			bonus/instruction3.c bonus/parsing.c bonus/parsing2.c bonus/split.c bonus/utils.c bonus/utils2.c bonus/utils3.c

OBJ_BONUS := $(SRC_BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): push_swap.h

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(NAME_BONUS)

$(OBJ_BONUS): bonus/checker.h

clean: 
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
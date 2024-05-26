# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 05:13:54 by aragragu          #+#    #+#              #
#    Updated: 2024/05/26 03:53:30 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rc
SRC = main.c parsing.c parsing2.c instruction.c instruction2.c instruction3.c \
		utils.c utils2.c utils3.c sorting.c sorting2.c sorting3.c
OBJ := $(SRC:%.c=%.o)


all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o : %.c push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
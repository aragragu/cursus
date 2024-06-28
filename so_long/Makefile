# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/04 23:43:09 by aragragu          #+#    #+#              #
#    Updated: 2024/06/28 20:56:26 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
FRM = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

SRC = so_long.c map_parsing.c ft_split.c mlx_intialization.c mouvement.c get_next_line.c \
		get_next_line_utils.c utils.c utils2.c map_parsing2.c map_parsing3.c ft_printf.c
		
OBJ := $(SRC:%.c=%.o)

all : $(NAME) 

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(FRM) -o $(NAME)


%.o : %.c so_long.h
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
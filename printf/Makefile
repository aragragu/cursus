# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 18:21:29 by aragragu          #+#    #+#              #
#    Updated: 2023/12/21 13:01:40 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rc
SRC = ft_printf.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_puthexa.c ft_putunsigned.c ft_putadress.c
OBJ := $(SRC:%.c=%.o)

%.o : %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiling"
	
all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "archiving"

clean: 
	$(RM) $(OBJ)
	@echo "removing object files"

fclean: clean
	$(RM) $(NAME)
	@echo "removing all"

re: fclean all

	
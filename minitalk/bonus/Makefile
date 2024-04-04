# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:07:05 by aragragu          #+#    #+#              #
#    Updated: 2024/03/26 09:17:35 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server_bonus
NAME_CLIENT = client_bonus

PRINTF = ../ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : printf $(NAME) $(NAME_CLIENT)

$(NAME) : server_bonus.o
	$(CC) $(CFLAGS) server_bonus.o $(PRINTF) -o $(NAME)

$(NAME_CLIENT) : client_bonus.o utils_bonus.o
	$(CC) $(CFLAGS) client_bonus.o utils_bonus.o $(PRINTF) -o $(NAME_CLIENT)
	
printf:
	@make -C ../ft_printf

%.o : %.c minitalk_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C ../ft_printf clean
	$(RM) server_bonus.o client_bonus.o utils_bonus.o

fclean : clean
	@make -C ../ft_printf fclean
	$(RM) $(NAME) $(NAME_CLIENT)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:07:05 by aragragu          #+#    #+#              #
#    Updated: 2024/03/26 09:15:19 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME_CLIENT = client

PRINTF = ../ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : printf $(NAME) $(NAME_CLIENT)

$(NAME) : server.o
	$(CC) $(CFLAGS) server.o $(PRINTF) -o $(NAME)

$(NAME_CLIENT) : client.o utils.o
	$(CC) $(CFLAGS) client.o utils.o $(PRINTF) -o $(NAME_CLIENT)

printf:
	@make -C ../ft_printf

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C ../ft_printf clean
	$(RM) server.o client.o utils.o

fclean : clean
	@make -C ../ft_printf fclean
	$(RM) $(NAME) $(NAME_CLIENT)

re : fclean all


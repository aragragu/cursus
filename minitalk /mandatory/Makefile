# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:07:05 by aragragu          #+#    #+#              #
#    Updated: 2024/03/25 00:14:10 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client

PRINTF = ../ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : printf $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : server.o
	$(CC) $(CFLAGS) server.o $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT) : client.o
	$(CC) $(CFLAGS) client.o $(PRINTF) -o $(NAME_CLIENT)

printf:
	@make -C ../ft_printf

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C ../ft_printf clean
	$(RM) server.o client.o

fclean : clean
	@make -C ../ft_printf fclean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re : fclean all


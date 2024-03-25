# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:07:05 by aragragu          #+#    #+#              #
#    Updated: 2024/03/25 00:12:52 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_BONUS_SERVER = server_bonus
NAME_BONUS_CLIENT = client_bonus

PRINTF = ../ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : printf $(NAME_BONUS_SERVER) $(NAME_BONUS_CLIENT)

$(NAME_BONUS_SERVER) : server_bonus.o
	@$(CC) $(CFLAGS) server_bonus.o $(PRINTF) -o $(NAME_BONUS_SERVER)

$(NAME_BONUS_CLIENT) : client_bonus.o
	@$(CC) $(CFLAGS) client_bonus.o $(PRINTF) -o $(NAME_BONUS_CLIENT)
	
printf:
	@make -C ../ft_printf

%.o : %.c minitalk_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C ../ft_printf clean
	@$(RM) server_bonus.o client_bonus.o 

fclean : clean
	@make -C ../ft_printf fclean
	@$(RM) $(NAME_BONUS_SERVER) $(NAME_BONUS_CLIENT)

re : fclean all

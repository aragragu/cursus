# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 18:37:36 by aragragu          #+#    #+#              #
#    Updated: 2023/11/29 18:31:20 by aragragu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = 	libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f
SRC = ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c \
	  ft_strlen.c ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c\
	  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_toupper.c ft_tolower.c ft_strrchr.c\
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c\
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	  ft_putnbr_fd.c

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ := $(SRC:%.c=%.o)
OBJ_B := $(SRC_B:%.c=%.o)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME):$(OBJ)
	$(AR) ${NAME} ${OBJ}

bonus : $(OBJ_B) $(OBJ)
	$(AR) ${NAME} $?	

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(bonus)

re: fclean all  

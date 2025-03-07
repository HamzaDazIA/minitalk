# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 18:17:42 by akella            #+#    #+#              #
#    Updated: 2025/03/07 01:16:03 by hdazia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC			= cc
CFLAGS		= -g

RM			= rm -rf

NAME_S		= server
NAME_C		= client

COMM_SRC		= 	ft_printf/ft_printf.c ft_printf/ft_putchar.c ft_printf/ft_putnbr.c \
			ft_printf/ft_putnbr_unsignd.c ft_printf/ft_printhex.c \
			ft_printf/ft_putstr.c ft_printf/ft_printp.c

SRC_S		= server.c 
SRC_C		= client.c


COMM_OBJ	= $(COMM_SRC:.c=.o)
OBJ_S		= $(SRC_S:.c=.o)
OBJ_C		= $(SRC_C:.c=.o)


all: client server

server: $(OBJ_S) $(COMM_OBJ)
	$(CC) $(CFLAGS) $(OBJ_S) $(COMM_OBJ) -o $(NAME_S)

client: $(OBJ_C) $(COMM_OBJ)
	$(CC) $(CFLAGS) $(COMM_OBJ) $(OBJ_C) -o $(NAME_C)


%.o: %.c minitalk.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_S) $(OBJ_C) $(COMM_OBJ) 

fclean: clean
	$(RM) $(NAME_S) $(NAME_C) 

re: fclean all
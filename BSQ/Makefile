# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzahi <oezzahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/03 09:55:16 by oezzahi           #+#    #+#              #
#    Updated: 2026/08/04 15:25:28 by oezzahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = srcs/bsq.c \
	srcs/find_bsq.c \
	srcs/print_bsq.c \
	srcs/check_map.c \
	srcs/check_map_1.c \
	srcs/check_map_2.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $(NAME)

%.o: %.c ./ft.h
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
	@rm -f ./srcs/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

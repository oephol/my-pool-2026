# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oezzahi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/02 09:07:44 by oezzahi           #+#    #+#              #
#    Updated: 2026/08/02 09:19:55 by oezzahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = do_op.c num_funcs.c ops.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c ops.h num_funcs.h
	@$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: fclean clean re all

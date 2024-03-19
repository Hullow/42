# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 18:43:15 by fallan            #+#    #+#              #
#    Updated: 2024/03/19 18:43:37 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

NAME= mlx-test
SRC = main.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all

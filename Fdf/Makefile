# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 20:06:01 by fallan            #+#    #+#              #
#    Updated: 2024/03/22 17:54:40 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlxtest
SRC = mlxtest.c
OBJ=$(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Iminilibx_macos -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
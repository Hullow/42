# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francis <francis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 13:51:59 by fallan            #+#    #+#              #
#    Updated: 2025/01/24 18:21:26 by francis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -ferror-limit=2

SRCS =	main.c \
		input.c \
		initialization.c \
		forks.c \
		simulation.c \
		routine.c \
		utils.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g
debug: re

sanitize: CFLAGS += -g -fsanitize=address
sanitize: re

tsan: CFLAGS += -g -fsanitize=thread
tsan: re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean
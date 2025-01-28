# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 13:51:59 by fallan            #+#    #+#              #
#    Updated: 2025/01/28 20:25:37 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		input_handling.c \
		initialization.c \
		forks.c \
		forks_utils.c \
		simulation.c \
		routine.c \
		routine_utils.c \
		general_utils.c
              
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
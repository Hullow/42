# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:35:22 by fallan            #+#    #+#              #
#    Updated: 2024/04/04 15:02:36 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libftprintf.a

LIBFT = ../libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c  ft_print_string.c ft_hex.c ft_putnbr.c ft_putnbr_unsigned.c ft_putchar.c ft_print_pointer.c

SRC = $(addprefix src/, $(SRCS))

all: $(NAME)

OBJ := $(SRC:%.c=%.o)

$(NAME) : $(OBJ) $(LIBFT)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
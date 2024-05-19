# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francis <francis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 20:06:01 by fallan            #+#    #+#              #
#    Updated: 2024/05/19 12:37:02 by francis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c input_handling.c insertion.c insertion_utils.c stack_actions.c insertion_moves.c stack_utils.c list_utils.c debug_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = ./lib/libft.a

FT_PRINTF = ./lib/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -ferror-limit=1

all: $(NAME) clean

sanitize: CFLAGS += -fsanitize=address -g3
sanitize: re clean

debug: CFLAGS += -g
debug: re

$(LIBFT):
	make -C ./lib/libft/ -f Makefile
	
$(FT_PRINTF):
	make -C ./lib/ft_printf/ -f Makefile

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L./lib -lft -lftprintf -o $(NAME)

clean:
	rm -f $(OBJ)
	for dir in ./lib/libft/ ./lib/ft_printf/; do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAME) $(LIBFT) $(FT_PRINTF) $(MLX)

re: fclean all clean

.PHONY: all sanitize clean fclean re
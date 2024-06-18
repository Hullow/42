# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 20:06:01 by fallan            #+#    #+#              #
#    Updated: 2024/06/18 15:50:14 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRC = sort.c sort_small_utils.c cost.c insertion.c input_handling.c $\
general_utils.c stack_actions.c stack_utils.c list_utils.c debug_utils.c

SRC_PS_MAIN = push_swap.c

SRC_BONUS = checker.c checker_utils.c

OBJ_PS_MAIN = $(SRC_PS_MAIN:.c=.o)

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = ./lib/libft.a

FT_PRINTF = ./lib/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 # -fmax-errors=5 # gcc: -fmax-errors=5 /// clang: -ferror-limit=1

all: $(NAME) clean

bonus: $(BONUS) clean

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

$(NAME): $(OBJ_PS_MAIN) $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_PS_MAIN) -L./lib -lft -lftprintf -o $(NAME)
	
$(BONUS): $(OBJ_BONUS) $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) -L./lib -lft -lftprintf -o $(BONUS)

clean:
	rm -f $(OBJ) $(OBJ_PS_MAIN) $(OBJ_BONUS)
	for dir in ./lib/libft/ ./lib/ft_printf/; do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAME) $(BONUS) $(LIBFT) $(FT_PRINTF) $(MLX)

re: fclean all clean

.PHONY: all bonus sanitize clean fclean re 
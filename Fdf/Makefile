# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 20:06:01 by fallan            #+#    #+#              #
#    Updated: 2024/04/04 18:08:37 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# include ./lib/libft/Makefile ./lib/ft_printf/Makefile

NAME = fdf

SRC = fdf_utils.c ./lib/get_next_line/src/get_next_line.c ./lib/get_next_line/src/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

LIBFT = ./lib/libft.a

FT_PRINTF = ./lib/libftprintf.a

MLX = ./lib/libmlx.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(MLX):
	make -C ./lib/minilibx/ -f Makefile

$(LIBFT):
	make -C ./lib/libft/ -f Makefile
	
$(FT_PRINTF):
	make -C ./lib/ft_printf/ -f	Makefile

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -c $< -o $@

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L./lib -lft -L./lib -lftprintf -L./lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

sanitize: $(OBJ)
	$(CC) -fsanitize=address $(CFLAGS) $(OBJ) -Llib -lft -lftprintf -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) $(MLX) $(LIBFT) $(FT_PRINTF)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
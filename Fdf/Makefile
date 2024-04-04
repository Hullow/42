# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 20:06:01 by fallan            #+#    #+#              #
#    Updated: 2024/04/04 16:57:49 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./lib/libft/Makefile ./lib/ft_printf/Makefile

NAME = fdf
SRC = fdf_utils.c ./lib/get_next_line/src/get_next_line.c ./lib/get_next_line/src/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
LIBFT = ./lib/libft/libft.a
FT_PRINTF = ./lib/ft_printf/ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	make -C ./lib/libft/ -f Makefile
	
$(FT_PRINTF):
	make -C ./lib/ft_printf/ -f	Makefile

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -Ilib/minilibx -c $< -o $@

# $(NAME): $(FT_PRINTF) $(LIBFT)
# 	ar -rcs $@ $^

$(NAME): $(OBJ) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L./lib/libft -lft -L./lib/ft_printf -lftprintf -L./lib/minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

sanitize: $(OBJ)
	$(CC) -fsanitize=address $(CFLAGS) $(OBJ) -Llib -lft -lftprintf -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ) $(FT_PRINTF) $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
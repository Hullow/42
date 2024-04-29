# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francis <francis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:49:42 by francis           #+#    #+#              #
#    Updated: 2024/04/27 17:58:50 by francis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(NAMES) = client server

SRC = server.c

OBJ = $(SRC:.c=.o)

FT_PRINTF = ./lib/libft_printf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAMES)

sanitize: CFLAGS += -fsanitize=address
sanitize: re

debug: CFLAGS += -g
debug: re

$(FT_PRINTF):
	make -C ./lib/ft_printf/ -f Makefile

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -c $< -o $@

$(NAMES): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) -L./lib -lftprintf -o $(NAME)

clean:
	rm -f $(OBJ)
	for dir in ./lib/ft_printf; do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAMES) $(FT_PRINTF)

re: fclean all

.PHONY: all sanitize debug clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:49:42 by francis           #+#    #+#              #
#    Updated: 2024/06/20 18:58:39 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = $(CLIENT) $(SERVER)

CLIENT = client

SERVER = server

SERVER_SRC = server.c

CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBFT = ./lib/libft/libft.a

FT_PRINTF = ./lib/ft_printf/libft_printf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAMES)

sanitize: CFLAGS += -fsanitize=address
sanitize: re

debug: CFLAGS += -g
debug: re

$(LIBFT):
	make -C ./lib/libft -f Makefile

$(FT_PRINTF):
	make -C ./lib/ft_printf/ -f Makefile

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -c $< -o $@

$(CLIENT): $(CLIENT_OBJ) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L./lib -lft -lftprintf -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L./lib -lft -lftprintf -o $(SERVER)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	for dir in ./lib/libft ./lib/ft_printf; do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAMES) $(FT_PRINTF) $(LIBFT)

re: fclean all

.PHONY: all sanitize debug clean fclean re

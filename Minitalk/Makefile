# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:49:42 by francis           #+#    #+#              #
#    Updated: 2024/07/01 20:01:56 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = client server

LIBFT = ./lib/libft/libft.a

FT_PRINTF = ./lib/ft_printf/libft_printf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L./lib -lft -lftprintf

CLIENT_SRC = client.c

CLIENT_OBJ = client.o

SERVER_SRC = server.c

SERVER_OBJ = server.o

%.o : %.c
	$(CC) $(CFLAGS) $(LIBFLAGS) -c $< -o $@

$(LIBFT):
	make -C ./lib/libft -f Makefile

$(FT_PRINTF):
	make -C ./lib/ft_printf -f Makefile

client: client.o
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFLAGS) -o client

server: server.o
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFLAGS) -o server

all: $(LIBFT) $(FT_PRINTF) $(NAMES)

sanitize: CFLAGS += -fsanitize=address
sanitize: re

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	for dir in ./lib/libft ./lib/ft_printf; do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(NAMES) $(FT_PRINTF) $(LIBFT)
	for dir in ./lib/libft ./lib/ft_printf; do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all sanitize debug clean fclean re client server

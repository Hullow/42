# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:49:42 by francis           #+#    #+#              #
#    Updated: 2024/07/06 22:32:51 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = client server

LIBFT = ./lib/libft.a

FT_PRINTF = ./lib/libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFLAGS = -L./lib -lft -lftprintf

CLIENT_SRC = client.c

CLIENT_OBJ = client.o

SERVER_SRC = server.c

SERVER_OBJ = server.o

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAMES)

client: $(LIBFT) $(FT_PRINTF) $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFLAGS) -o client

server: $(LIBFT) $(FT_PRINTF) $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFLAGS) -o server

$(FT_PRINTF): $(LIBFT)
	make -C ./lib/ft_printf -f Makefile

$(LIBFT):
	make -C ./lib/libft -f Makefile

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
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(NAMES) # $(FT_PRINTF) $(LIBFT)
	for dir in ./lib/libft ./lib/ft_printf; do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all sanitize debug clean fclean re
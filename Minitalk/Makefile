# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francis <francis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 17:49:42 by francis           #+#    #+#              #
#    Updated: 2024/07/01 15:45:18 by francis          ###   ########.fr        #
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

$(LIBFT):
	make -C ./lib/libft -f Makefile

$(FT_PRINTF):
	make -C ./lib/ft_printf -f Makefile

all: $(LIBFT) $(FT_PRINTF) $(NAMES)

sanitize: CFLAGS += -fsanitize=address
sanitize: re

debug: CFLAGS += -g
debug: re

%.o : %.c
	$(CC) $(CFLAGS) -Ilib -c $< -o $@

$(CLIENT): $(CLIENT_OBJ) $(LIBFT) $(FT_PRINTF) 
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L./lib -lft -lftprintf -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L./lib -lft -lftprintf -o $(SERVER)

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

.PHONY: all sanitize debug clean fclean re

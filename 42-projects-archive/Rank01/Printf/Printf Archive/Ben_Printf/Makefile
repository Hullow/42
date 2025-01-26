# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 14:28:20 by bwach             #+#    #+#              #
#    Updated: 2023/11/05 13:31:25 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT_DIR = libft

SRC_FILES = ft_printf.c ft_print_hex.c ft_print_unsigned.c ft_printf_utils.c ft_print_ptr.c\

OBJ = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp ${LIBFT_DIR}/libft.a .
	@mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
	@echo "Compilation done"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_DIR)
	
clean: 
	$(RM) $(OBJ)
	@make clean -C ${LIBFT_DIR}
	@echo "Clean done"
	
fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/libft.a
	@echo "Fclean done"

re: fclean all

.PHONY: clean fclean re
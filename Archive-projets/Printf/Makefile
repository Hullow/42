# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fallan <fallan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 15:35:22 by fallan            #+#    #+#              #
#    Updated: 2023/12/12 15:35:36 by fallan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c  ft_print_string.c ft_hex.c ft_putnbr.c ft_putnbr_unsigned.c ft_putchar.c ft_print_pointer.c $\
libft/ft_isalnum.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memmove.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c $\
libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strtrim.c libft/ft_atoi.c libft/ft_isalpha.c $\
libft/ft_memchr.c libft/ft_memset.c libft/ft_strjoin.c libft/ft_strncmp.c libft/ft_substr.c libft/ft_bzero.c libft/ft_isascii.c libft/ft_memcmp.c $\
libft/ft_split.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_tolower.c libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strchr.c $\
libft/ft_strlcpy.c libft/ft_strrchr.c libft/ft_toupper.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c $\
libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c $\

all: $(NAME)

OBJ := $(SRC:%.c=%.o)

$(NAME) : $(OBJ) $()
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
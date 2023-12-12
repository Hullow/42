# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwach <bwach@student.42lausanne.ch>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 08:48:48 by bwach             #+#    #+#              #
#    Updated: 2023/10/30 00:01:44 by bwach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LDFLAGS = -L.
LDLIBS = -lft

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	ft_isprint.c ft_strlen.c\
	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c\
	ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c\
	ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c
	
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	ft_lstdelone.c ft_lstclear.c ft_lstmap.c ft_lstiter.c 
	
OBJ = $(SRC:.c=.o)

BONUSOBJ = $(BONUS:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -g -I . -c $< -o $(<:.c=.o) 

all: $(NAME)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus : $(OBJ) $(BONUSOBJ)
		ar rc $(NAME) $(OBJ) $(BONUSOBJ)
		ranlib $(NAME)

.PHONY: clean fclean re
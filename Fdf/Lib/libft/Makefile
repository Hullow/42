NAME = ../libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I. -I..

DEPS = ../libft.h

SRC = ft_isalnum.c ft_isprint.c ft_itoa.c ft_memmove.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c $\
ft_putstr_fd.c ft_strdup.c ft_striteri.c ft_strlen.c ft_strmapi.c ft_strtrim.c ft_atoi.c ft_isalpha.c $\
ft_memchr.c ft_memset.c ft_strjoin.c ft_strncmp.c ft_substr.c ft_bzero.c ft_isascii.c ft_memcmp.c $\
ft_split.c ft_strlcat.c ft_strnstr.c ft_tolower.c ft_calloc.c ft_isdigit.c ft_memcpy.c ft_strchr.c $\
ft_strlcpy.c ft_strrchr.c ft_toupper.c

SRC = $(addprefix src/, $(SRCS))

all: $(NAME)

OBJ := $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

SRC_BONUS = ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c

OBJ_BONUS := $(SRC_BONUS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

bonus: $(NAME) $(OBJ_BONUS)
	ar -rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

NAME = libftprintf.all

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c

all: $(NAME)

OBJ := $(SRC:%.c=%.o)

$(NAME) : $(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
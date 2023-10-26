NAME = libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

CPPFLAGS=-I.

DEPS = Libft.h

SRC = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strjoin.c ft_strlen.c ft_strrchr.c ft_tolower.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlcat.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_calloc.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strdup.c ft_strlcpy.c ft_strnstr.c ft_substr.c

OBJ := $(SRC:%.c=%.o)

all: $(NAME) clean

$(NAME) : $(OBJ)
	ar -rcs $@ $^

%.o: %.c # to generate the object files
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

# -c: to generate the object files
# $(CC) $(CFLAGS) $(CPPFLAGS)  # -c: to generate the object files

# ar -rcs $(OBJ) -o $(NAME) # to create an archive of the object files

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
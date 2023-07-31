# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

# Target executable
TARGET = rush02

# Source files
SRCS = rush02.c ft_atoi.c ft_handle_multi_utils.c ft_number_utils.c ft_output_utils.c ft_string_utils.c ft_find_number_int_texte.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS)

# Clean all object files, the executable, and temporary files
fclean: clean
	rm -f $(TARGET)

# Rebuild the project
re: fclean all

# Phony targets to avoid conflicts with filenames
.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra -Werror -pedantic -fsanitize=address

TARGET = libft.a

SRCS = \
	ft_bzero.c \
	ft_calloc.c \
	ft_isprint.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_islower.c \
	ft_isupper.c \
	ft_islower.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strrev.c \
	ft_strlen.c \
	ft_strnlen.c \
	ft_strmapi.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean 
	$(MAKE) all

.PHONY: all clean fclean re

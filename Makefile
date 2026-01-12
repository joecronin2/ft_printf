CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS += -I$(LIBFT_DIR)

TARGET = libftprintf.a
SRCS = printf.c util.c write.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(TARGET): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(TARGET)
	ar rcs $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

clean:
	rm -f $(OBJS) 
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean 
	$(MAKE) all

.PHONY: all clean fclean re

CC = cc
CFLAGS = -Wall -Wextra
# CFLAGS = -Wall -Wextra -Werror

TARGET = printf

SRCS = printf.c util.c write.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(TARGET)

re: fclean 
	$(MAKE) all

.PHONY: all clean fclean re

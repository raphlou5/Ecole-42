SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
LDFLAGS = -L./printf -lprintf

all: server client

bonus: server client

server: server.o printf
	$(CC) -o $@ $< $(LDFLAGS)

client: client.o printf
	$(CC) -o $@ $< $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<

printf:
	make -C printf

clean:
	rm -f $(OBJECTS)
	make -C printf clean
	
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all bonus printf clean fclean re

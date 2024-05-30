SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC

all: printf.a server client

server: server.o 
	$(CC) -o $@ $< ./printf/printf.a

client: client.o
	$(CC) -o $@ $^ ./printf/printf.a

%.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJECTS)
	make -C printf clean
    
fclean: clean
	rm -f server client

re: fclean all

.PHONY: all bonus printf.a clean fclean re

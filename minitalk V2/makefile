SOURCES = server.c client.c manage_errors.c utils.c
OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = bonus/server_bonus.c bonus/client_bonus.c manage_errors.c utils.c
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: printf.a server client

server: server.o utils.o
	$(CC) -o $@ $< ./printf/printf.a utils.o

client: client.o manage_errors.o
	$(CC) -o $@ $^ ./printf/printf.a utils.o

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

bonus/%.o: bonus/%.c
	$(CC) -c $(CFLAGS) $< -o $@

bonus: printf.a server_bonus client_bonus

server_bonus: bonus/server_bonus.o utils.o
	$(CC) -o $@ $< ./printf/printf.a utils.o

client_bonus: bonus/client_bonus.o manage_errors.o utils.o
	$(CC) -o $@ $^ ./printf/printf.a

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)
	make -C printf clean

fclean: clean
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all bonus printf.a clean fclean re


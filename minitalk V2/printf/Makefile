NAME = printf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SOURCES = ft_printf.c ft_printhex.c ft_printpointer.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunsnumber.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

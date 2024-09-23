NAME        := minishell
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 

SRCS        :=      libft/ft_putstr.c \
                          libft/utils.c \
                          srcs/main.c \
                          srcs/minishell.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re



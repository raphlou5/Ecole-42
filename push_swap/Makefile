NAME     := push_swap
CC       := cc
FLAGS    := -Wall -Wextra -Werror 


SRCS        :=      src/push_swap/push_swap.c \
                          src/push_swap/init_b_to_a.c \
                          src/push_swap/split.c \
                          src/push_swap/errors.c \
                          src/push_swap/init_a_to_b.c \
                          src/push_swap/stack_init.c \
                          src/push_swap/stack_init2.c \
                          src/push_swap/stack_utils.c \
                          src/commands/rev_rotate_both.c \
                          src/commands/rotate.c \
                          src/commands/push.c \
                          src/commands/rotate_both.c \
                          src/commands/rev_rotate.c \
                          src/commands/swap.c \
                          src/commands/three_sort.c \
                          src/commands/turk_sort.c \
                          inc/printf/ft_printf_utils.c \
                          inc/printf/ft_printf.c \
                          inc/printf/ft_printf_utils2.c \
                          inc/libft/ft_strlen.c \
                          inc/libft/ft_lstadd_front.c \
                          inc/libft/ft_strrchr.c \
                          inc/libft/ft_lstmap.c \
                          inc/libft/ft_strmapi.c \
                          inc/libft/ft_strlcpy.c \
                          inc/libft/ft_memchr.c \
                          inc/libft/ft_lstclear.c \
                          inc/libft/ft_putnbr_fd.c \
                          inc/libft/ft_putstr_fd.c \
                          inc/libft/ft_isalnum.c \
                          inc/libft/ft_putendl_fd.c \
                          inc/libft/ft_striteri.c \
                          inc/libft/ft_strchr.c \
                          inc/libft/ft_toupper.c \
                          inc/libft/ft_strjoin.c \
                          inc/libft/ft_atoi.c \
                          inc/libft/ft_lstdelone.c \
                          inc/libft/ft_lstiter.c \
                          inc/libft/ft_isprint.c \
                          inc/libft/ft_strdup.c \
                          inc/libft/ft_strtrim.c \
                          inc/libft/ft_memmove.c \
                          inc/libft/ft_bzero.c \
                          inc/libft/ft_calloc.c \
                          inc/libft/ft_isalpha.c \
                          inc/libft/ft_memset.c \
                          inc/libft/ft_strncmp.c \
                          inc/libft/ft_lstnew.c \
                          inc/libft/ft_itoa.c \
                          inc/libft/ft_substr.c \
                          inc/libft/ft_split.c \
                          inc/libft/ft_strlcat.c \
                          inc/libft/ft_lstadd_back.c \
                          inc/libft/ft_putchar_fd.c \
                          inc/libft/ft_tolower.c \
                          inc/libft/ft_isascii.c \
                          inc/libft/ft_lstlast.c \
                          inc/libft/ft_memcpy.c \
                          inc/libft/ft_isdigit.c \
                          inc/libft/ft_lstsize.c \
                          inc/libft/ft_memcmp.c \
                          inc/libft/ft_strnstr.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

${NAME}:	${OBJS}
			${CC} ${FLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o

fclean:		clean
			@ ${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re



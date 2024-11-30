CC = gcc

CFLAGS = -Wextra -Werror -Wall

SRCS = SRCS/ft_add.c SRCS/ft_atoi.c SRCS/ft_div.c SRCS/ft_do_op.c SRCS/ft_mod.c SRCS/ft_mult.c SRCS/ft_putchar.c SRCS/ft_putnbr.c SRCS/ft_putstr.c SRCS/ft_sub.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

NAME = do_op

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o:%.c
	${CC} ${CFLAGS} -c $< -o $@
	
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

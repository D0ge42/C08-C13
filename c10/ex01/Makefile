CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_cat.c srcs/ft_putstr.c srcs/ft_strlen.c

OBJS = ${SRCS:.c=.o}

NAME = ft_cat

RM = rm -f

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: fclean re all clean


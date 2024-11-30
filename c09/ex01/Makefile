#Targets are file names, separated by spaces. Tipically there's only one per rule.
#Commands are a series of step tipically used to make the target(s). These need to starts with a tab, not space.
#prerequisites are also file names, separated by spaces. These files need to exists before the target's commands are run.

#List of source files that will be compiled.
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

#Specifies the directory where the source files are located.
PRE = ./srcs/

#Uses addprefix function to add the path ./srcs/ to each file in src.
SRCS = ${addprefix ${PRE}, ${SRC}}

#Convert the .c file paths in SRCS into .o (object files) using the substitution reference ${VAR:.c=.o}
OBJS = ${SRCS:.c=.o}

#Directory containing the header file.
HEAD = ./includes/

#Name of the file library being created.
NAME = libft.a

#Creates or update the archive(static library) file libft.a
AR = ar rc

#Deletes file without prompting ?
RM = rm -f 

#Indexes the library to improve linking performance.
LIB = ranlib 

#GNU c compiler
GCC = gcc

#Flags
CFLAGS = -Wall -Wextra -Werror

#When we execute make all (or just make, since all is the default target)make will try to build the target libft.a
all: ${NAME}

#Implicit rule that tells to Make to convert every .c file to .o
.c.o:
		${GCC}${CFLAGS}-c -I ${HEAD} $< -o ${<:.c=.o}

#This rules creates the static library libft.a. 
#${OBJS} Ensures all .o files are compiled before creating the library.
#${AR} Adds the .o files to the archive libft.a
#${LIB} Indexes the library for faster linking.

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

#Rule to clean
clean:
			rm -f {OBJS}

#Delete also the library.
fclean: clean rm -f {NAME}

#Delete everything and rebuilds library from scratch
re: fclean all

.PHONY: all clean fclean re

#!/bin/bash
gcc -Wall -Wextra -Werror -c ft_putchar.c ft_putstr.c ft_swap.c ft_strlen.c ft_strcmp.c 
#ar = command to create modify and extract from archives. R is replace, c is create and tells are to create the archive
#if it doesn't already exists.
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
#Ranlib is used to create an index for the linker. This way the linker will be able to create the library much faster.
ranlib libft.a

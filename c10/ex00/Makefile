CC = gcc

CFLAGS = -Wall -Wextra -Werror

TARGET = ft_display_file

SRCS = ft_display_file.c

OBJS = $(SRCS:.c=o)

#Default Target

all:$(TARGET)

#Target is the default binary executable file's name that we'll create.
#File compilation works like this file.c -> file.o -> file
#First is the file we've written.
#File.o is an object file which is a bridge between file.c and file.
#File is the binary executable file.

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

#Implicit rule. For each .c file i can create a .o file.
#% is  a placeholder for the name. 
#$< automatic variable, which representes the prerequisite of the rule. %.c in this case (es main.c)
#$@ automatic variable, representing the target of the rule. For example (main.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -rf $(TARGET)



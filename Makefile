#Project name                                                                   
NAME=get_next_line
#Compiler                                                                       
CC=cc
#Compiler flags                                                                 
C_FLAGS=-Wall -Werror -Wextra -g
#.c files                                                                       
SRC=get_next_line.c get_next_line_utils.c
#.h files
INCLUDE=get_next_line.h
#root path                                                                      
ROOT=${CURDIR}
#Object
OBJ=$(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)	

re: fclean all
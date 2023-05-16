#Project name                                                                   
NAME=get_next_line
#Compiler                                                                       
CC=cc
#Compiler flags                                                                 
C_FLAGS=-Wall -Werror -Wextra
#.c files                                                                       
SRC=get_next_line.c
#root path                                                                      
ROOT=${CURDIR}

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf *.o
	
fclean: clean
	rm -rf get_next_line	

re: fclean all
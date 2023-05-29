#Project name                                                                   
NAME=get_next_line
#Bonus name
NAME_BONUS=get_next_line_bonus
#Compiler                                                                       
CC=cc
#Compiler flags                                                                 
C_FLAGS=-Wall -Werror -Wextra -g
#.c files                                                                       
SRC=get_next_line.c get_next_line_utils.c main.c
#Bonus source
SRC_BONUS=get_next_line_bonus.c get_next_line_utils_bonus.c
#root path                                                                      
ROOT=${CURDIR}
#Object
OBJ=$(SRC:.c=.o)
#Bonus object
OBJ_BONUS=$(SRC_BONUS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(C_FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
	
fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

b: $(OBJ_BONUS)
	$(CC) $(C_FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
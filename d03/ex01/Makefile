CC = c++ 
CFLAG =  -std=c++98 -Wall -Wextra -Werror -g
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

OUT = exec

all : $(OUT)

$(OUT) : $(OBJ) *.hpp
	$(CC) $(OBJ) -o $(OUT)

obj/%.o : %.cpp 
	@mkdir -p obj
	$(CC) $(CFLAG)  -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean 
	rm -rf $(OUT)
re : fclean all

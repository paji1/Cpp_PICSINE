CC = c++ 
CFLAG =  -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp ClapTrap.cpp
INC = Zombie.hpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

OUT = exec

all : $(OUT)

$(OUT) : $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

obj/%.o : %.cpp 
	@mkdir -p obj
	$(CC) $(CFLAG)  -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean 
	rm -rf $(OUT)
re : fclean all

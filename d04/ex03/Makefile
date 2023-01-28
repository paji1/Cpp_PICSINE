CC = c++ 
CFLAG =  -std=c++98 -Wall -Wextra -Werror -g -Wshadow  -Wno-shadow
SRC = AMateria.cpp ICharacter.cpp Cure.cpp  main.cpp  Ice.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

OUT = exec

all : $(OUT)

$(OUT) : $(OBJ) 
	$(CC) $(OBJ) -o $(OUT)

obj/%.o : %.cpp *.hpp
	@mkdir -p obj
	$(CC) $(CFLAG)  -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean 
	rm -rf $(OUT)
re : fclean all

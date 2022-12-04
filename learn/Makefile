CC = c++ 
CFLAG = -std=c++98  -I include
SRC = main.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

OUT = ./bin/hello_cpp

all : $(OUT)
	$(OUT) | cat -e
$(OUT) : $(OBJ)
	$(CC) $(OBJ) -o $(OUT)

obj/%.o : src/%.cpp
	$(CC) $(CFLAG)  -c $< -o $@



clean : 
	rm -rf $(OBJ)
fclean : clean 
	rm -rf $(OUT)
re : fclean all

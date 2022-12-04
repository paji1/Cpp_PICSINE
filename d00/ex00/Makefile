CC = c++ 
CFLAG = -std=c++98  
SRC = megaphone.cpp
OBJ = $(addprefix obj/, $(SRC:.cpp=.o))

OUT = megaphone

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

CC = g++
objects = 1 
all : $(objects)

$(objects): % : src/%.cpp
	$(CC) $< -o bin/$@.o
CC = g++
objects = 1 2 3 4 5
all : $(objects)

$(objects): % : src/%.cpp
	$(CC) $< -g -o bin/$@.o

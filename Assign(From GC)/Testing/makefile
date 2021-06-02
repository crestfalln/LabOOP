CC = g++
objects = 5
all : $(objects)

$(objects): % : src/%.cpp
	$(CC) $< -g -o bin/$@.o

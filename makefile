CC = g++
objects = 1 2
all : $(objects)

$(objects): % : src/%.cpp
	$(CC) $< -o bin/$@.o

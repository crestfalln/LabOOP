CC = g++
objects = 1 2
all : $(objects)

$(objects): % : src/%.cpp
	$(CC) -O2 $< -o bin/$@.o
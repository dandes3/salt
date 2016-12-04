# basic makefile, makes into executable called hash

all: hash.cpp hashmain.cpp
	g++ -Wall hash.cpp hashmain.cpp -lm -o hash

clean:
	$(RM) hash



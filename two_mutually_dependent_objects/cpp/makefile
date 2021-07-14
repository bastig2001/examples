CPPFLAGS=-std=c++17 -Werror

all: example.cpp object.o channel.h message.h
	g++ $(CPPFLAGS) example.cpp -o example.out

object.o: object.cpp channel.h message.h
	g++ $(CPPFLAGS) -c object.cpp

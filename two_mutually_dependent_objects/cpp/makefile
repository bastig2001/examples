CPPFLAGS=-std=c++17 -Werror

all: example.cpp object.o channel.h message.h
	g++ $(CPPFLAGS) -pthread example.cpp object.o -o example.out

object.o: object.cpp channel.h message.h
	g++ $(CPPFLAGS) -c object.cpp

CXX=clang++

CPPFLAGS=-fcolor-diagnostics -fansi-escape-codes -o

EXECUTABLE=bin/main

SRCS=*.cpp **/*.cpp

INCLUDE=-Iinclude/

SFMLFLAGS=-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

MISCFLAGS=-Wall -Wextra -Wpedantic

all:
	$(CXX) $(CPPFLAGS) $(EXECUTABLE) $(SRCS) $(INCLUDE) $(SFMLFLAGS) $(MISCFLAGS)
a.out : main.cpp Retriver.o
	g++ -Wall Retriver.o main.cpp

Retriver.o : Retriver.cpp Retriver.h
	g++ -c -Wall Retriver.cpp
